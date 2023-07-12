#include<iostream>
#include<queue>
using namespace std;
int arr[501][501];
int visit[501][501];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int x = 0; x < n; x++) {
		for (int y = 0; y < m; y++) {
			cin >> arr[x][y];
		}
	}
	int num = 0, mx = 0;
	queue<pair<int, int>>q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (visit[i][j] || arr[i][j] == 0)
				continue;
			num++;
			visit[i][j] = 1;
			q.push({ i,j });
			int area = 0;
			while (!q.empty()) {
				area++;
				pair<int, int>cur = q.front();
				q.pop();
				for (int x = 0; x < 4; x++) {
					int mx = cur.first + dx[x];
					int my = cur.second + dy[x];
					if (mx < 0 || mx >= n || my < 0 || my >= m)
						continue;
					if (visit[mx][my] || arr[mx][my] != 1)
						continue;
					visit[mx][my] = 1;
					q.push({ mx,my });
				}

				mx = max(mx, area);
			}
		}
	}
	cout << num << endl << mx;
}