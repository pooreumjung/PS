#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N, M, K;
vector<int>parent;
vector<int>candy;
vector<int>allcandy;
vector<vector<int>>friends;
void Union(int a, int b);
int find(int a);
int dp[30001][3001];
int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M >> K;

	parent.resize(N + 1);
	candy.resize(N + 1);
	friends.resize(N + 1);
	allcandy.resize(N + 1);

	for (int i = 0; i <= N; i++)
		parent[i] = i;

	for (int i = 1; i <= N; i++)
		cin >> candy[i];
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		if (find(a) != find(b))
			Union(a, b);
	}

	vector<int>v;
	for (int i = 1; i <= N; i++) {
		int p = find(i);
		friends[p].push_back(i);
		v.push_back(p);
	}
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());

	for (int i = 0; i < v.size(); i++) {
		int p = v[i];
		for (int j = 0; j < friends[p].size(); j++)
			allcandy[i] += candy[friends[p][j]];
	}
	int answer = 0;
	for (int i = 0; i < v.size(); i++) {
		int cur = v[i];
		int cnt = friends[cur].size();
		int can = allcandy[i];
		for (int j = K - 1; j >= 0; j--) {
			if (j - cnt >= 0)
				dp[i + 1][j] = max(dp[i][j], dp[i][j - cnt] + can);
			else
				dp[i + 1][j] = dp[i][j];
			answer = max(answer, dp[i + 1][j]);
		}
	}

	cout << answer;
}
void Union(int a, int b) {
	a = find(a);
	b = find(b);
	if (a <= b)
		parent[b] = a;
	else
		parent[a] = b;
}
int find(int a) {
	if (a == parent[a])
		return a;
	else
		return parent[a] = find(parent[a]);
}