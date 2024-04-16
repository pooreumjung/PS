#include<iostream>
#include<vector>
using namespace std;
#define MAX 301

vector<int>graph[MAX];
vector<int>graph2[MAX];
int pick[MAX];
int pick2[MAX];
bool visit[MAX];
bool visit2[MAX];
bool dfs(int per);
bool dfs2(int per);
int N, M, K1, K2;
int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M >> K1 >> K2;

	for (int i = 1; i <= K1; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
	}
	for (int i = 1; i <= K2; i++) {
		int a, b;
		cin >> a >> b;
		graph2[a].push_back(b);
	}

	int count = 0, count2 = 0;
	for (int i = 1; i <= N; i++) {
		fill(visit, visit + MAX, false);
		if (dfs(i))
			count++;
	}
	for (int i = 1; i <= N; i++) {
		fill(visit2, visit2 + MAX, false);
		if (dfs2(i))
			count2++;
	}
	if (count >= count2)
		cout << "그만 알아보자";
	else
		cout << "네 다음 힐딱이";
}

bool dfs(int per)
{
	for (int i = 0; i < graph[per].size(); i++) {
		int end = graph[per][i];
		if (visit[end])
			continue;
		visit[end] = true;
		if (pick[end] == 0 || dfs(pick[end])) {
			pick[end] = per;
			return true;
		}
	}
	return false;
}
bool dfs2(int per)
{
	for (int i = 0; i < graph2[per].size(); i++) {
		int end = graph2[per][i];
		if (visit2[end])
			continue;
		visit2[end] = true;
		if (pick2[end] == 0 || dfs2(pick2[end])) {
			pick2[end] = per;
			return true;
		}
	}
	return false;
}