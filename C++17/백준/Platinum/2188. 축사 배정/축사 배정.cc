#include<iostream>
#include<vector>
using namespace std;
#define MAX 201
int N, M;

vector<int>graph[MAX];
int node[MAX];
bool visit[MAX];
bool dfs(int cow);

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;

	for (int i = 1; i <= N; i++) { // 그래프 구현
		int number;
		cin >> number;
		while (number--) {
			int shed;
			cin >> shed;
			graph[i].push_back(shed);
		}
	}

	int count = 0;
	for (int i = 1; i <= N; i++) {
		fill(visit, visit + MAX, false);
		if (dfs(i))
			count++;
	}

	cout << count;
}

bool dfs(int cow)
{
	for (int i = 0; i < graph[cow].size(); i++) {
		int shed = graph[cow][i];
		if (visit[shed])
			continue;
		visit[shed] = true;
		if (node[shed] == 0 || dfs(node[shed])) {
			node[shed] = cow;
			return true;
		}
	}
	return false;
}
