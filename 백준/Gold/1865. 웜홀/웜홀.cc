#include<iostream>
#include<tuple>
#include<vector>
#include<limits.h>
using namespace std;

typedef tuple<int, int, int>edge;
vector<long>dist;
bool time_travel(int n, vector<edge>edges);
int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	for (int x = 0; x < T; x++) {

		vector<edge>tree;
		int N, M, W;
		cin >> N >> M >> W;

		dist.resize(N + 1);	
		fill(dist.begin(), dist.end(), INT_MAX);

		for (int i = 0; i < M; i++) {
			int start, end, time;
			cin >> start >> end >> time;
			tree.push_back(edge(start, end, time));
			tree.push_back(edge(end, start, time));
		}

		for (int i = 0; i < W; i++) {
			int start, end, time;
			cin >> start >> end >> time;
			tree.push_back(edge(start,end, -time));
		}

		dist[1] = 0;
		bool iscycle = time_travel(N, tree);

		if (iscycle)
			cout << "YES" << "\n";
		else
			cout << "NO" << "\n";	
	}
}
bool time_travel(int n,vector<edge>tree) {

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < tree.size(); j++) {
			edge edges = tree[j];
			int start = get<0>(edges);
			int end = get<1>(edges);
			int time = get<2>(edges);
			if (dist[end] > dist[start] + time) {
				dist[end] = dist[start] + time;
			}
		}
	}

	for (int j = 0; j < tree.size(); j++) {
		edge edges = tree[j];
		int start = get<0>(edges);
		int end = get<1>(edges);
		int time = get<2>(edges);
		if (dist[end] > dist[start] + time) {
			return true;
		}
	}
	return false;
}
