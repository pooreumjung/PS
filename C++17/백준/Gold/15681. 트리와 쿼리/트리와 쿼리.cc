#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>>graph;
vector<int>parent;
vector<int>sevSize;
int N, R, Q;
void makeTree(int route);
void countNode(int node);
int count1 = 0;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> R >> Q;

	graph.resize(N + 1);
	parent.resize(N + 1);
	sevSize.resize(N + 1);

	parent[R] = -1;

	for (int i = 0; i < N-1; i++) {
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	makeTree(R);
	countNode(R);
	for (int i = 0; i < Q; i++) {
		int node;
		cin >> node;
		if (node == R)
			cout << N << "\n";
		else {			
			cout << sevSize[node] << "\n";
		}
	}

}
void makeTree(int route) {
	for (int next : graph[route]) {
		if (parent[next] == -1 || parent[next] != 0)
			continue;
		parent[next] = route;
		makeTree(next);
	}
}
void countNode(int node) {
	sevSize[node] = 1;
	for (int next : graph[node]) {
		if (parent[node] == next)
			continue;
		countNode(next);
		sevSize[node] += sevSize[next];
	}
}

