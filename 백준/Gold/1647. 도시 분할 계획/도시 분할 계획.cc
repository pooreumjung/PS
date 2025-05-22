#include<iostream>
#include<vector>
#include<queue>
using namespace std;

typedef struct edge {
	int start, end, value;
	bool operator > (const edge& temp)const {
		return value > temp.value;
	}
}edge;
vector<int>parent;
priority_queue<edge, vector<edge>, greater<edge>>pq;
priority_queue<edge, vector<edge>, greater<edge>>q;
void Union(int start, int end);
int find(int a);
int N, M;
int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;

	parent.resize(N + 1);
	for (int i = 0; i <= N; i++)
		parent[i] = i;

	for (int i = 0; i < M; i++) {
		int start, end, value;
		cin >> start >> end >> value;
		pq.push(edge{ start,end,value });
	}

	int sum = 0, ncount = 0;
	while (ncount < N - 2) {
		edge cur = pq.top();
		q.push(cur);
		pq.pop();
		if (find(cur.start) != find(cur.end)) {
			ncount++;
			sum += cur.value;
			Union(cur.start, cur.end);
		}
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
	if (a == parent[a])
		return a;
	else
		return parent[a] = find(parent[a]);
}
