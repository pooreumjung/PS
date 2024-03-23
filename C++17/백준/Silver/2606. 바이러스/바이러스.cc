#include<iostream>
#include<vector>
using namespace std;


vector<vector<int>>tree;
vector<bool>visit;
void dfs(int node);
int ncount = 0;
int main() {

	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int N,M;
	cin >> N>>M;
	tree.resize(N + 1);
	visit.resize(N + 1);

	for (int i = 0; i < M; i++) {
		int start, end;
		cin >> start >> end;
		tree[start].push_back(end);
		tree[end].push_back(start);
	}

	
	dfs(1);
	cout << ncount;

}
void dfs(int node) {
	
	visit[node] = true;

	for (int next : tree[node]) {
		if (!visit[next]) {
			visit[next] = true;
			ncount++;
			dfs(next);
		}
	}
}