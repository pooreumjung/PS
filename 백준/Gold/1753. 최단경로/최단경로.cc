#include<iostream>
#include<vector>
#include<queue>
#include<limits.h>
using namespace std;

typedef pair<int, int>edge;
vector<vector<pair<int, int>>>A; // 인접 리스트
vector<int>D; // 최단 거리 배열
vector<bool>visit; // 방문 여부 체크
priority_queue<edge, vector<edge>, greater<edge>>q;
int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int V, E;
	cin >> V >> E; // 정점과 간선의 개수
	int k;
	cin >> k;
	A.resize(V + 1);
	D.resize(V + 1);
	visit.resize(V + 1);
	fill(visit.begin(), visit.end(), false);
	fill(D.begin(), D.end(), INT_MAX);

	for (int i = 0; i < E; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		A[u].push_back({ v,w }); // 인접 리스트 업데이트
	}

	D[k] = 0; // 시작 지점은 0으로
	q.push({ 0,k });

	while (!q.empty()) {
		edge cur = q.top();
		q.pop();
		int c_v = cur.second; // 노드
		if (visit[c_v]) // 이미 방문한 노드라면 continue
			continue;
		visit[c_v] = true; // 방문 여부 check

		for (int i = 0; i < A[c_v].size(); i++) {
			edge tmp = A[c_v][i];
			int next = tmp.first; // 방문할 노드
			int value = tmp.second; // 방문할 노드의 가중치
			if (D[next] > D[c_v] + value) { // 방문할 곳의 value보다 출발지 + 가중치가 작다면
				D[next] = value + D[c_v];
				q.push({ D[next],next });
			}
		}
	}
	for (int i = 1; i <= V; i++) {
		if (D[i] == INT_MAX)
			cout << "INF" << '\n';
		else
			cout << D[i] << '\n';
	}

}