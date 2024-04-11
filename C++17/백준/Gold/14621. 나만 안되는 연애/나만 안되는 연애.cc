#include<iostream>
#include<queue>
#include<vector>
#include<set>
using namespace std;

typedef struct Edge {
	int start, end, value;
	bool operator > (const Edge& temp)const {
		return value > temp.value;
	}

}Edge;

int N, M, s, e, v;
vector<char>collage;
vector<int>parent;
set<int>mySet;
void Union(int a, int b);
int find(int a);

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	collage.resize(N + 1);
	for (int i = 1; i <= N; i++)
		cin >> collage[i];

	parent.resize(N + 1);
	for (int i = 1; i <= N; i++)
		parent[i] = i;

	priority_queue<Edge, vector<Edge>, greater<Edge>>pq;
	for (int i = 0; i < M; i++) {
		cin >> s >> e >> v;
		pq.push(Edge{ s,e,v });
	}

	int rSum = 0, usedEdge = 0;
	bool isMST = false;
	while (M--) {
		Edge tmp = pq.top();
		pq.pop();
		int start = tmp.start;
		int end = tmp.end;
		int value = tmp.value;
		if (collage[start] != collage[end]) {
			if (find(start) != find(end)) {
				Union(start, end);
				rSum += value;
				usedEdge++;
			}
		}
		if (usedEdge == N - 1) {
			isMST = true;
			break;
		}
	}
	
	if (isMST)
		cout << rSum;
	else
		cout << -1;
}

void Union(int a, int b)
{
	int node1 = find(a);
	int node2 = find(b);

	if (node1 != node2) {
		if (node1 > node2)
			parent[node1] = node2;
		else
			parent[node2] = node1;
	}

}

int find(int a)
{
	if (a == parent[a])
		return a;
	else
		return parent[a] = find(parent[a]);
}

