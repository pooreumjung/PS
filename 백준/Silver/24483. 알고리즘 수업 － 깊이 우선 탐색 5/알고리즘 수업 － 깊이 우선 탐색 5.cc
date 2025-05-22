#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define ll long long
bool visit[100001];
ll depth[100001];
ll order[100001];
vector<vector<int>>list;
void dfs(int node);
ll cnt = 1;
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
	order[R] = cnt++;
	dfs(R);

	ll res = 0;
	for (int i = 1; i <= N; i++) {
		ll mul= depth[i] * order[i];
		res += mul;
	}
	cout << res;
}
void dfs(int node) {

	visit[node] = true;

	for(int next:list[node]) {
		if (visit[next])
			continue;
		depth[next] = depth[node] + 1;
		order[next] = cnt++;
		dfs(next);
	}
}