#include<iostream>
#include<vector>
#include<queue>
using namespace std;


vector<int>powerStation;
vector<int>parent;
void Union(int a, int b);
int find(int a);
int N, M, K, u, v, w,power;
typedef struct Edge {
	int u, v, w;
	bool operator > (const Edge& temp)const {
		return w > temp. w;
	}
}Edge;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M >> K;

	parent.resize(N + 1);
	powerStation.resize(N + 1);
	for (int i = 1; i <= N; i++)
		parent[i] = i;

	priority_queue<Edge, vector<Edge>, greater<Edge>>pq;
	
	for (int i = 0; i < K; i++) {
		cin >> power;
		powerStation[power] = 1;
	}

	for (int i = 0; i < M; i++) {
		cin >> u >> v >> w;
		pq.push(Edge{ u, v, w });
	}

	int useEdge = 0;
	int powerSum = 0;

	while (useEdge < N - K) {
		Edge now = pq.top();
		pq.pop();
		int start = now.u;
		int end = now.v;
		int value = now.w;

		int node1 = find(start);
		int node2 = find(end);
		if (node1 != node2) {
			if (powerStation[node1] == 1 && powerStation[node2] == 1)
				continue;
			else {
				Union(start, end);
				powerSum += value;
				useEdge++;
			}
		}
	}
	cout << powerSum;
}

void Union(int a, int b)
{
	int node1 = find(a);
	int node2 = find(b);

	
	if (node1 != node2) {
		if (powerStation[node1] != 1 && powerStation[node2] != 1) {
			if (node1 > node2)
				parent[node1] = node2;
			else
				parent[node2] = node1;
		}
		else {
			if (powerStation[node1] == 1)
				parent[node2] = node1;
			else
				parent[node1] = node2;
		}
		
	}
}

int find(int a)
{
	if (a == parent[a])
		return a;
	else
		return parent[a] = find(parent[a]);
}
