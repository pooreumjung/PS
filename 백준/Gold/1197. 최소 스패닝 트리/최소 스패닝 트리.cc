#include<iostream>
#include<tuple>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
vector<int>parent;
typedef struct edge{
	int start, end, value;
	bool operator > (const edge& temp)const {
		return value > temp.value;
	}
}edge;
void Union(int start, int end);
int find(int a);
int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int V, E;
	cin >> V >> E;
	priority_queue<edge, vector<edge>, greater<edge>>pq;
	parent.resize(V + 1);

	for (int i = 0; i <= V; i++) // parent배열 초기화
		parent[i] = i;

	for (int i = 0; i < E; i++) {
		int start, end, value;
		cin >> start >> end >> value;
		pq.push(edge{ start, end, value });
	}

	int count = 0;
	int sum = 0;
	while (count < V - 1) {
		edge cur = pq.top();
		int start = cur.start;
		int end = cur.end;
		int value = cur.value;
		if (find(start) != find(end)) {
			Union(start, end);
			count++;
			sum += value;
		}
		pq.pop();
	}
	cout << sum;
}
void Union(int start, int end) {
	int node1 = find(start);
	int node2 = find(end);

	if (node1 != node2)
		parent[node2] = node1;
}
int find(int a) {
	if (parent[a] == a)
		return a;
	else
		return parent[a] = find(parent[a]);
}