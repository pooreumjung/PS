#include<iostream>
#include<queue>
#include<vector>
#include<limits.h>
#include<algorithm>
using namespace std;

typedef pair<int, int>edge; // 자료형
vector<vector<edge>>mlist; // 인접 리스트
vector<int>mdistance; // x를 제외한 최단거리배열
vector<int>xdistance; // x에서 시작하는 최단거리배열
vector<bool>visit; // 방문 여부 체크
vector<int>result;
int N, E, X;
void dijkstra(int start);
int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	
	cin >> N >> E>>X;
	mdistance.resize(N + 1); // 배열들 크기 조절
	xdistance.resize(N + 1); // 배열들 크기 조절
	visit.resize(N + 1); // 배열들 크기 조절
	result.resize(N + 1);
	mlist.resize(N + 1);

	for (int i = 0; i < E; i++) { // 인접 리스트 업데이트
		int start, end, time;
		cin >> start >> end >> time;
		mlist[start].push_back({ end,time });
	}

	fill(mdistance.begin(), mdistance.end(), INT_MAX); // 나머지 배열들 초기화
	//fill(xdistance.begin(), mdistance.end(), INT_MAX); // 나머지 배열들 초기화
	fill(visit.begin(), visit.end(), false); // 나머지 배열들 초기화

	for (int i = 1; i <= N; i++) {
		if (i == X)
			continue;
		else {
			dijkstra(i);
			fill(mdistance.begin(), mdistance.end(), INT_MAX); // 나머지 배열들 초기화
			fill(visit.begin(), visit.end(), false); // 나머지 배열들 초기화
		}
	}
	dijkstra(X);
	sort(result.begin(), result.end());
	cout << result[N];
}
void dijkstra(int start) {
	priority_queue<edge, vector<edge>, greater<edge>>q;
	mdistance[start] = 0;
	q.push({ 0,start });
	visit[start] = true;

	while (!q.empty()) {
		edge cur = q.top();
		q.pop();
		int now = cur.second; // 방문할 노드		
		for (int i = 0; i < mlist[now].size(); i++) { // 인접 리스트 탐색
			if (!visit[now])
				visit[now] = true;			
				edge tmp = mlist[now][i];
				int city = tmp.first; // 다음에 갈 도시
				int time = tmp.second; // 걸리는 시간
				if (mdistance[city] > mdistance[now] + time) {
					mdistance[city] = mdistance[now] + time;
					q.push({ mdistance[city],city });
				}			
		}
	}
	if(start!=X)
		result[start] += mdistance[X];
	else
	{
		for (int i = 1; i <= N; i++) {
			result[i] += mdistance[i];
		}
	}
}
