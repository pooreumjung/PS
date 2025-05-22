#include<iostream>
#include<cmath>
#include<vector>
#include<queue>
using namespace std;


int executeLCA(int node1, int node2);
vector<bool>visit;
vector<int>parent;
vector<int>depth;
vector<vector<int>>tree;

void BFS(int node);
int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	tree.resize(N + 1);
	visit.resize(N + 1);
	depth.resize(N + 1);
	parent.resize(N + 1);

	for (int i = 0; i < N-1; i++) {
		int start, end;
		cin >> start >> end;
		tree[start].push_back(end);
		tree[end].push_back(start);
	}
	
	BFS(1);
	int M;
	cin >> M;


	for (int i = 0; i < M; i++) {
		int node1, node2;
		cin >> node1 >> node2;
		cout << executeLCA(node1, node2) << '\n';
	}
}
int executeLCA(int node1, int node2) {
	if (depth[node1] < depth[node2]) {
		int temp = node1;
		node1 = node2;
		node2 = temp;
	}
	while (depth[node1] != depth[node2]) {
		node1 = parent[node1];
	}
	while (node1 != node2) {
		node1 = parent[node1];
		node2 = parent[node2];
	}
	return node1;
}
void BFS(int node) {
	queue<int>myqueue;
	myqueue.push(node);
	visit[node] = true;
	int level = 1;
	int now_size = 1;
	int count = 0;
	while (!myqueue.empty()) {
		int now_node = myqueue.front();
		myqueue.pop();
		for (int next : tree[now_node]) {
			if (!visit[next]) {
				visit[next] = true;
				myqueue.push(next);
				parent[next] = now_node;
				depth[next] = level;
			}
		}
		count++;
		if (count == now_size) {
			count = 0;
			now_size = myqueue.size();
			level++;
		}
	}
}
