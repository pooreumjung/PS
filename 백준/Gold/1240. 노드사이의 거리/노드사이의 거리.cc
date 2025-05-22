#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<pair<int, int>>>tree;
vector<int>esum;
vector<bool>visit;
vector<int>v;
int startnode, endnode;
int edgesum;
void dfs(int node);
int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	tree.resize(N + 1);
	visit.resize(N + 1);
	esum.resize(N + 1);

	for (int i = 0; i < N - 1; i++) {
		int start, end, value;
		cin >> start >> end >> value;
		tree[start].push_back(make_pair(end, value));
		tree[end].push_back(make_pair(start, value));
	}

	for (int i = 0; i < M; i++) {
		edgesum = 0;

		cin >> startnode >> endnode;
		dfs(startnode);
		dfs(endnode);
		sort(v.begin(), v.end());
		cout << v[0]<<'\n';
		v.clear();
	}
}
void dfs(int node) {
	if (node == endnode) {
		if(esum[node]!=0)
		v.push_back(esum[node]);
		return;
	}
	for (pair<int, int>next : tree[node]) {
		if (!visit[next.first]) {
			if(!visit[next.first])
			esum[next.first] = esum[node] + next.second;

			visit[next.first] = true;
			dfs(next.first);
			visit[next.first] = false;
			esum[next.first] = 0;
		}
	}
}