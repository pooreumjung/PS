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
void Union(int start, int end);
int find(int a);
int N, M;
vector<int>parent;
int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	
	while (true) {
		cin >> N >> M;
		if (N == 0 && M == 0)
			return 0;
		priority_queue<edge, vector<edge>, greater<edge>>pq;		
		parent.resize(N + 1);
		for (int i = 0; i <= N; i++)
			parent[i] = i;
		long every = 0;
		for (int i = 0; i < M; i++) {
			int start, end, value;
			cin >> start >> end >> value;
			pq.push(edge{ start,end,value });
			every += value;
		}
		long sum = 0, ncount = 0;
		while (ncount < N - 1) {
			edge cur = pq.top();
			pq.pop();
			if (find(cur.start) != find(cur.end)) {
				ncount++;
				sum += cur.value;
				Union(cur.start, cur.end);
			}
		}
		cout << every - sum << '\n';
		fill(parent.begin(), parent.end(), 0);
	}
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
