#include<iostream>
#include<vector>
#include<limits.h>
#include<queue>
using namespace std;

typedef pair<int, int>cur;
vector<vector<cur>>tree;
vector<bool>visit;
vector<int>dist;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	tree.resize(N + 1);
	visit.resize(N + 1);
	dist.resize(N + 1);

	fill(visit.begin(), visit.end(), false);
	fill(dist.begin(), dist.end(), INT_MAX);

	for (int i = 0; i < M; i++) {
		int start, end, value;
		cin >> start >> end >> value;
		tree[start].push_back(cur(end, value));
		tree[end].push_back(cur(start, value));
	}

	int s, t;
	cin >> s >> t;

	priority_queue<cur, vector<cur>, greater<cur>>pq;
	pq.push(cur(0, s));
	dist[s] = 0;

	while (!pq.empty()) {
		cur temp = pq.top();
		int node = temp.second;
		pq.pop();
		if (!visit[node]) {
			visit[node] = true;
			for (cur f : tree[node]) {
				dist[f.first] = min(dist[f.first], dist[node] + f.second);
				pq.push(cur(dist[f.first], f.first));
			}
		}
	}
	cout << dist[t];
}