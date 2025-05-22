#include<iostream>
#include<queue>
#include<vector>
using namespace std;

void Union(int start, int end);
int find(int a);
vector<int>parent;
typedef struct edge {
	int start, end, value;
	bool operator > (const edge& temp) const {
		return value > temp.value;
	}
}edge;
vector<vector<int>>map;
priority_queue<edge, vector<edge>, greater<edge>>pq;
int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N,sum=0;
	cin >> N;
	map.resize(N + 1);
	parent.resize(N + 1);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			char tempc = cin.get();
			if (tempc == '\n') {
				tempc = cin.get();
			}
			int temp = 0;
			if (tempc >= 'a' && tempc <= 'z') {
				temp = tempc - 'a' + 1;
			}
			else if (tempc >= 'A' && tempc <= 'Z') {
				temp = tempc - 'A' + 27;
			}
			sum = sum + temp; 	// 총 랜선의 길의 저장
			if (i != j && temp != 0) {
				pq.push(edge{ i, j, temp });
			}
		}
	}
	
	for (int i = 0; i <= N; i++)
		parent[i] = i;

	int Ncount = 0;
	int Nsum = 0;
	while (!pq.empty()) {
		edge cur = pq.top();
		pq.pop();
		if (find(cur.start) != find(cur.end)) {
			Union(cur.start, cur.end);
			Nsum += cur.value;
			Ncount++;
		}
	}
	if (Ncount == N - 1)
		cout << sum-Nsum;
	else
		cout << -1;
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