#include<iostream>
#include<queue>
using namespace std;
int arr[1001][1001];
int dis[1001][1001];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> m >> n;
	queue<pair<int, int>>q;
	for (int x = 0; x < n; x++) {
		for (int y = 0; y < m; y++) {
			cin >> arr[x][y];
			if (arr[x][y] == 1)
				q.push({ x,y });
			if (arr[x][y] == 0)
				dis[x][y] = -1;
		}
	}
	while (!q.empty()) {
		pair<int, int>cur = q.front();
		q.pop();
		for (int x = 0; x < 4; x++) {
			int mx = cur.first + dx[x];
			int my = cur.second + dy[x];
			if (mx < 0 || my < 0 || mx >= n || my >= m)
				continue;
			if (dis[mx][my] >= 0)
				continue;
			dis[mx][my] = dis[cur.first][cur.second]+1;
			q.push({ mx,my });
		}

	}
	int ans = 0;
	for (int x = 0; x < n; x++) {
		for (int y = 0; y < m; y++) {
			if (dis[x][y] == -1) {
				cout << -1;
				return 0;
			}
			ans = max(ans, dis[x][y]);
		}

	}
	cout << ans;
}