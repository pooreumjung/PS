#include<iostream>
#include<vector>
#include<stack>
using namespace std;

static vector<vector<int>>A;
static vector<bool>visit;
void dfs(int v);

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	A.resize(N + 1);
	visit = vector<bool>(N + 1, false);

	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		A[u].push_back(v);
		A[v].push_back(u);
	}
	
	int count = 0;

	for (int i = 1; i < N + 1; i++) {
		if (!visit[i]) {
			count++;
			dfs(i);
		}
	}
	cout << count;
}

void dfs(int v) {
	if (visit[v])
		return;
	visit[v] = true;

	for (int i : A[v]) {
		if (visit[i] == false)
			dfs(i);
	}
}