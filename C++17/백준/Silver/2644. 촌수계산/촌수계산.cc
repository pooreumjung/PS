#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>>tree;
vector<int>visit;
int s, e;
bool check = false;
int ct = 0,res=0;
void dfs(int node);
int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	tree.resize(n + 1);
	visit.resize(n + 1);
	int m;

	cin >> s >> e;
	cin >> m;

	for (int i = 0; i < m; i++) {
		int start,end;
		cin >> start >> end;
		tree[start].push_back(end);
		tree[end].push_back(start);
	}

	 dfs(s);

	 if (check)
		 cout << visit[e];
	 else
		 cout << -1;
}
void dfs(int node) {

	if (node == e) {
		check = true;
		return;
	}
		
	for (int next : tree[node]) {
		if (!visit[next]) {
			visit[next] = visit[node] + 1;
			dfs(next);
		}
	}
	return;
}