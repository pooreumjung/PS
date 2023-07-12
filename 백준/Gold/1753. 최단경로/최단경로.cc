#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int V, E;
int K;
int u, v, w;
int INF = 1000000;

vector<pair<int, int> > adj[20001];
int dist[20001];


void dijkstra(int src) {

	dist[src] = 0;
	priority_queue<pair<int, int> > pq;
	pq.push(make_pair(0, src));

	while (!pq.empty()) {
		int cost = -pq.top().first;
		int here = pq.top().second;
		pq.pop();

		if (dist[here] < cost) continue;

		for (int i = 0; i < adj[here].size(); i++) {
			int there = adj[here][i].first;
			int nextDist = cost + adj[here][i].second;

			if (dist[there] > nextDist) {
				dist[there] = nextDist;
				pq.push(make_pair(-nextDist, there));
			}
		}
	}
}

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> V >> E;
	cin >> K;

	for (int i = 1; i <= V; i++) {
		dist[i] = INF;
	}
	

	for (int i = 0; i < E; i++) {
		cin >> u >> v >> w;
		adj[u].push_back(make_pair(v, w));
	}

	dijkstra(K);

	for (int i = 1; i <= V; i++) {
		if (dist[i] == INF) {
			cout << "INF" << endl;
		}
		else
			cout << dist[i] << endl;
	}
}
