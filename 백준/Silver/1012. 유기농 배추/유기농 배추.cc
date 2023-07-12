#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int arr[51][51];
int vis[51][51];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int bfs(int a,int b, int c) {
	for (int x = 0; x < a; x++) {
		for (int y = 0; y < b; y++) {
			arr[x][y] = 0;
			vis[x][y] = 0;
		}
	}
	for (int x = 0; x < c; x++) {
		int dx, dy;
		cin >> dx >> dy;
		arr[dx][dy] = 1;
	}
	int num = 0;
	queue<pair<int, int>>q;
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
			if (arr[i][j] == 0 || vis[i][j])
				continue;
			q.push({ i,j });
			num++;
			vis[i][j] = 1;
			while (!q.empty()) {
				pair<int, int>cur = q.front();
				q.pop();
				for (int x = 0; x < 4; x++) {
					int mx = cur.first + dx[x];
					int my = cur.second + dy[x];
					if (mx < 0 || my < 0 || mx >= a || my >= b)
						continue;
					if (arr[mx][my] == 0 || vis[mx][my])
						continue;
					vis[mx][my] = 1;
					q.push({ mx,my });
				}

			}
		}
	}
	return num;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for (int x = 0; x < n; x++) {
		int a, b, c;
		cin >> a >> b >> c;
		cout << bfs(a, b, c) << endl;
	}
	
}