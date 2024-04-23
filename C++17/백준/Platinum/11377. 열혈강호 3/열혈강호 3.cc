#include<iostream>
#include<vector>
using namespace std;
int N, M, K;
vector<int>v[1001];
bool visit[1001];
int work[1001];
bool dfs(int node);
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M >> K;
	int num, wo,res=0,k=0;
	for (int i = 1; i <= N; i++) {
		cin >> num;
		for (int j = 0; j < num; j++) {
			cin >> wo;
			v[i].push_back(wo);
		}
	}
	for (int i = 1; i <= N; i++) {
		fill(visit, visit + 1001, false);
		if (dfs(i)) res++;
	}
	for (int i = 1; i <= N; i++) {
		fill(visit, visit + 1001, false);
		if (dfs(i)) {
			res++;
			k++;
		}
		if (k == K) break;
	}
	cout << res;
}

bool dfs(int node) {
	for (int i = 0; i < v[node].size(); i++) {
		int next = v[node][i];
		if (visit[next])continue;
		visit[next] = true;
		if (work[next] == 0 || dfs(work[next])) {
			work[next] = node;
			return true;
		}
	}
	return false;
}