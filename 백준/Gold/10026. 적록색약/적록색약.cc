#include<iostream>
#include<queue>
using namespace std;
char arr[101][101];
int vis[101][101];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int four(int a) {
	queue<pair<int, int>>q;
	int num = 0;
	for (int x = 0; x < a; x++) {
		for (int y = 0; y < a; y++) {
			if (vis[x][y])
				continue;
			if (arr[x][y] == 'R') {
				num++;
				q.push({ x,y });
				while (!q.empty()) {
					pair<int, int>cur = q.front();
					q.pop();
					for (int x = 0; x < 4; x++) {
						int mx = cur.first + dx[x];
						int my = cur.second + dy[x];
						if (mx < 0 || my < 0 || mx >= a || my >= a)
							continue;
						if (arr[mx][my] != 'R' || vis[mx][my])
							continue;
						vis[mx][my] = 1;
						q.push({ mx,my });

					}
				}

			}
			if (arr[x][y] == 'G') {
				num++;
				q.push({ x,y });
				while (!q.empty()) {
					pair<int, int>cur = q.front();
					q.pop();
					for (int x = 0; x < 4; x++) {
						int mx = cur.first + dx[x];
						int my = cur.second + dy[x];
						if (mx < 0 || my < 0 || mx >= a || my >= a)
							continue;
						if (arr[mx][my] != 'G' || vis[mx][my])
							continue;
						vis[mx][my] = 1;
						q.push({ mx,my });

					}
				}

			}
			if (arr[x][y] == 'B') {
				num++;
				q.push({ x,y });
				while (!q.empty()) {
					pair<int, int>cur = q.front();
					q.pop();
					for (int x = 0; x < 4; x++) {
						int mx = cur.first + dx[x];
						int my = cur.second + dy[x];
						if (mx < 0 || my < 0 || mx >= a || my >= a)
							continue;
						if (arr[mx][my] != 'B' || vis[mx][my])
							continue;
						vis[mx][my] = 1;
						q.push({ mx,my });

					}
				}

			}

		}
	}

	return num;
	

}
int three(int a) {
	for (int x = 0; x < a; x++) {
		for (int y = 0; y < a; y++)
			vis[x][y] = 0;
	}
	queue<pair<int, int>>q;
	int num = 0;
	for (int x = 0; x < a; x++) {
		for (int y = 0; y < a; y++) {
			if (vis[x][y])
				continue;
			if (arr[x][y] == 'B') {
				num++;
				q.push({ x,y });
				while (!q.empty()) {
					pair<int, int>cur = q.front();
					q.pop();
					for (int x = 0; x < 4; x++) {
						int mx = cur.first + dx[x];
						int my = cur.second + dy[x];
						if (mx < 0 || my < 0 || mx >= a || my >= a)
							continue;
						if (arr[mx][my] != 'B' || vis[mx][my])
							continue;
						vis[mx][my] = 1;
						q.push({ mx,my });

					}
				}

			}
			else {
				num++;
				q.push({ x,y });
				while (!q.empty()) {
					pair<int, int>cur = q.front();
					q.pop();
					for (int x = 0; x < 4; x++) {
						int mx = cur.first + dx[x];
						int my = cur.second + dy[x];
						if (mx < 0 || my < 0 || mx >= a || my >= a)
							continue;
						if (arr[mx][my] =='B' || vis[mx][my])
							continue;
						vis[mx][my] = 1;
						q.push({ mx,my });

					}
				}

			}
		}
	}
	return num;
}
int main() {
	int a;
	cin >> a;
	for (int x = 0; x < a; x++) {
		for (int y = 0; y < a; y++) {
			cin >> arr[x][y];
		}
	}
	cout << four(a) << " ";
	cout<< three(a);
}