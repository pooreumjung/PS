#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>>tree;
vector<bool>visit;
void dfs(int node);
vector<int>parent;
int treeHeight;
void executeLCA(int node);
int result;
int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	for (int x = 0; x < T; x++) {

		treeHeight = 0;
		result = 0;
		int N;
		cin >> N;

		tree.resize(N + 1);
		visit.resize(N + 1);
		parent.resize(N + 1);
	
		int start, end;
		for (int i = 0; i < N - 1; i++) {
			cin >> start >> end;
			tree[end].push_back(start);
		}

		int node1, node2;
		cin >> node1 >> node2;

		dfs(node1);
		parent[node1] = 1;
		executeLCA(node2);
		cout << result << '\n';
		tree.clear();
		parent.clear();
	}


}
void dfs(int node) {

	for (int next : tree[node]) {
		if (!visit[next]) {
			visit[next] = true;
			parent[next] = 1;
			dfs(next);
			visit[next] = false;
		}
	}
}
void executeLCA(int node) {
	if (parent[node] == 1) {
		result = node;
		return;
	}
	for (int next : tree[node]) {
		if (!visit[next]) {
			visit[next] = true;
			executeLCA(next);
			visit[next] = false;
		}
	}
}
