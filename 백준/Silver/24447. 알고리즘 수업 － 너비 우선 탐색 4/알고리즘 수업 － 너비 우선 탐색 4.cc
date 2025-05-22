#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
#define ll long long

int N, M, R;
vector<vector<int>>mlist;
bool visit[100001];
ll depth[100001];
ll order[100001];
ll cnt = 1;
int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M >> R;
	mlist.resize(N + 1);

	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		mlist[u].push_back(v);
		mlist[v].push_back(u);
	}

	for (int i = 1; i <= N; i++) {
		sort(mlist[i].begin(), mlist[i].end());
		depth[i] = -1;
	}

	depth[R] = 0;
	visit[R] = true;
	order[R] = cnt++;

	queue<int>q;
	q.push(R);
	while (!q.empty()) {
		int node = q.front();
		q.pop();
		for(int next:mlist[node]){
			if (visit[next])
				continue;
			visit[next] = true;
			depth[next] = depth[node] + 1;
			order[next] = cnt++;
			q.push(next);
		}
	}

	ll res = 0;
	for (int i = 1; i <= N; i++) {
		ll mul = order[i] * depth[i];
		res += mul;
	}
	cout << res;
}