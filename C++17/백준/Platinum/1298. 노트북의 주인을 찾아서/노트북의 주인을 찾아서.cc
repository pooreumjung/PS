#include<iostream>
#include<vector>
using namespace std;
#define MAX 101

int N, M;
vector<int>graph[MAX];
int node[MAX];
bool visit[MAX];
bool dfs(int person);
int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int per, com;
		cin >> per >> com;
		graph[per].push_back(com);
	}

	int count = 0;
	for (int i = 1; i <= N; i++) {
		fill(visit, visit + MAX, false);
		if (dfs(i))
			count++;
	}
	cout << count;
}

bool dfs(int person)
{
	for (int i = 0; i < graph[person].size(); i++) {
		int com = graph[person][i];
		if (visit[com])
			continue;
		visit[com] = true;
		if (node[com] == 0 || dfs(node[com])) {
			node[com] = person;
			return true;
		}
	}
	return false;
}
