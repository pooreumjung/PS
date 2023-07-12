#include<iostream>
#include<queue>
using namespace std;
int vis[305][305]; //횟수를 기록하는 배열
int dx[8] = { -2,-2,-1,-1,1,1,2,2 };
int dy[8] = { 1,-1,2,-2,2,-2,1,-1 };
queue<pair<int, int>>q;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int test;
	cin >> test;
	for (int i = 0; i < test; i++) {
		int len, x, y, x_final, y_final;
		cin >> len;
		cin >> x >> y;
		cin >> x_final >> y_final;
		if (x == x_final && y == y_final) {
			cout << '0' << '\n';
			continue;
		}
		for (int i = 0; i < len; i++) {
			for (int j = 0; j < len; j++)
				vis[i][j] = -1;
		}
		vis[x][y] = 0;
		q.push({ x,y });
		while (!q.empty()) {
			pair<int, int>cur = q.front();
			q.pop();
			for (int d = 0; d < 8; d++) {
				int mx = cur.first + dx[d];
				int my = cur.second + dy[d];
				if (mx < 0 || my < 0 || mx >= len || my >= len)
					continue;
				if (vis[mx][my] >= 0)
					continue;
				vis[mx][my] = vis[cur.first][cur.second] + 1;
				q.push({ mx,my });

			}
		}
		cout << vis[x_final][y_final] << "\n";
	}
}