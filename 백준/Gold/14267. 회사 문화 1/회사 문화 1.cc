#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>>graph;
vector<int>boss;
vector<long>praise;
int N, M;
void makeTree(int node);
void countPraise(int node);

int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;

	graph.resize(N + 1);
	praise.resize(N + 1);
	boss.resize(N + 1);

	for (int i = 1; i <= N; i++) {
		int b;
		cin >> b;
		if (b == -1)
			continue;
		else {
			graph[i].push_back(b);
			graph[b].push_back(i);
		}
	}
	
	makeTree(1);

	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		praise[u] += v;
	}

	countPraise(1);

	for (int i = 1; i <= N; i++)
		cout << praise[i] << " ";
}

void makeTree(int node)
{
	for (int next : graph[node]) {
		if (boss[next] != 0 || boss[next] == -1)
			continue;
		boss[next] = node;
		makeTree(next);
	}
}

void countPraise(int node)
{
	for (int next : graph[node]) {
		if (next < node)
			continue;
		else {
			praise[next] += praise[node];
			countPraise(next);			
		}
	}
}
