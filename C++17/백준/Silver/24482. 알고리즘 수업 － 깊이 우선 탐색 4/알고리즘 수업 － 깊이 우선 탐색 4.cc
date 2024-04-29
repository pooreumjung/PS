#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool visit[100001];
int depth[100001];
vector<vector<int>>list;
void dfs(int node);
int cnt = 1;
int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, R;
	cin >> N >> M >> R;

	list.resize(N + 1);

	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		list[u].push_back(v);
		list[v].push_back(u);
	}
	for (int i = 1; i <= N; i++) {
		sort(list[i].begin(), list[i].end());
	}

	for (int i = 0; i < 100001; i++)
		depth[i] = -1;

	depth[R] = 0;
	dfs(R);

	for (int i = 1; i <= N; i++)
		cout << depth[i] << "\n";
}
void dfs(int node) {

	visit[node] = true;

	for (int i = list[node].size() - 1; i >= 0; i--) {
		int next = list[node][i];
		if (visit[next])
			continue;
		depth[next] = depth[node] + 1;
		dfs(next);
	}
}