#include<iostream>
#include<vector>
using namespace std;


vector<vector<pair<int, int>>>tree;
vector<int>valuesum;
vector<bool>visit;
void dfs(int node);
int startnode = 0;
int maxvalue = 0;
int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	tree.resize(N + 1);
	visit.resize(N + 1);
	valuesum.resize(N + 1);

	for (int i = 0; i < N - 1; i++) {
		int start, end, value;
		cin >> start >> end >> value;
		tree[start].push_back(make_pair(end,value));
		tree[end].push_back(make_pair(start, value));
	}

	visit[1] = true;
	dfs(1);
	maxvalue = 0;
	fill(visit.begin(), visit.end(), false);
	fill(valuesum.begin(), valuesum.end(), 0);
	visit[startnode] = true;
	dfs(startnode);
	cout << maxvalue;
}
void dfs(int node) {


	for (pair<int, int>next : tree[node]) {
		if (!visit[next.first]) {
			visit[next.first] = true;
			valuesum[next.first] += valuesum[node] + next.second;
			dfs(next.first);
		}
	}
	if (maxvalue < valuesum[node]) {
		maxvalue = valuesum[node];
		startnode = node;
	}
}