#include<iostream>
#include<limits.h>
#include<vector>
#include<queue>
using namespace std;

typedef pair<int, int > edge;
vector<vector<edge>>mlist;
vector<int>mdistance;
vector<bool>visit;
int dijkstra(int start, int end);
int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;
	mlist.resize(N + 1); // 배열 크기 설정
	mdistance.resize(N + 1); // 배열 크기 설정
	visit.resize(N + 1);
	fill(visit.begin(), visit.end(), false); // 방문 배열 초기화
	fill(mdistance.begin(), mdistance.end(), INT_MAX); // 최단 거리 배열 초기화
	
	for (int i = 0; i < M; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		mlist[u].push_back({ v,w }); // 인접 리스트 업데이트
	}
	
	int start, end; // 시작 지점과 도착 지점
	cin >> start >> end;

	cout << dijkstra(start, end); // 결과 출력
}
int dijkstra(int start, int end) {
	priority_queue < edge, vector<edge>, greater<edge>>q; // 큐 생성
	mdistance[start] = 0;
	q.push({ 0,start });
	while (!q.empty()) {
		edge cur = q.top();
		int c_v = cur.second;
		q.pop();
		if (visit[c_v]) // 탐색했던 노드라면 건너뛰기
			continue;
		visit[c_v] = true; // 방문 표시
		for (int i = 0; i < mlist[c_v].size(); i++) {
			edge tmp = mlist[c_v][i];
			int next = tmp.first; // 방문할 곳
			int value = tmp.second; // 방문하는 곳으로의 가중치
			if (mdistance[next] > mdistance[c_v] + value) {
				mdistance[next] = mdistance[c_v] + value;
				q.push({ mdistance[next],next });
			}
		}
	}
	return mdistance[end];
}