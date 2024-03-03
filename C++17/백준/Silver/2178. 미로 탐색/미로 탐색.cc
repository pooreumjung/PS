#include<iostream>
#include<queue>
#include<string>
using namespace std;
string str[102];
int visit[101][101];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int x = 0; x < n; x++)
		cin >> str[x];
	queue<pair<int, int>>q;
	q.push({ 0,0 });
	visit[0][0] = 0;
	while (!q.empty()) {
		pair<int, int>cur = q.front();
		q.pop();
		for (int x = 0; x < 4; x++) {
			int mx = cur.first + dx[x];
			int my = cur.second + dy[x];
			if (mx < 0 || my < 0 || mx >= n || my >= m)
				continue;
			if (visit[mx][my] || str[mx][my] != '1')
				continue;
			visit[mx][my] = visit[cur.first][cur.second] + 1;
			q.push({ mx,my });
		}
	}
	int d = n - 1;
	int k = m - 1;
	cout << visit[d][k]+1;
}