#include<iostream>
#include<limits.h>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

typedef pair<int, int > edge;
vector<vector<edge>>mlist;
vector<int>mdistance;
vector<bool>visit;
int result[1001];
vector<int>dif;
int N, M;
void dijkstra(int start, int end);
int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	mlist.resize(N + 1); // 배열 크기 설정
	mdistance.resize(N + 1); // 배열 크기 설정
	visit.resize(N + 1);
	dif.resize(N + 1);
	fill(visit.begin(), visit.end(), false); // 방문 배열 초기화
	fill(mdistance.begin(), mdistance.end(), INT_MAX); // 최단 거리 배열 초기화
	fill(dif.begin(), dif.end(), INT_MAX);
	for (int i = 0; i < M; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		mlist[u].push_back({ v,w }); // 인접 리스트 업데이트
	}

	int start, end; // 시작 지점과 도착 지점
	cin >> start >> end;
	dijkstra(start, end);
	cout << mdistance[end]<<'\n';

	vector<int>res;
	int x = end;
	while (x != start) {
		res.push_back(x);
		x = result[x];
	}
	res.push_back(x);
	reverse(res.begin(), res.end());
	cout << res.size() << '\n';
	for (auto c : res)
		cout << c << " ";
}
void dijkstra(int start, int end) {
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
				result[next] = c_v;
			}
		}
		
	}

}