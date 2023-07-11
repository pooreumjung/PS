#include<iostream>
#include<queue>
using namespace std;
char arr[1001][1001];
int time1[1001][1001];
int time2[1001][1001];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
void bfs() {
	queue<pair<int, int>>q1;
	queue<pair<int, int>>q2;
	int w, h;
	cin >> w >> h;

	for (int i = 0; i < 1001; i++) {
		for (int j = 0; j < 1001; j++) {
			time1[i][j] = -1;
			time2[i][j] = -1;
		}
	}

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == '*') {
				time1[i][j] = 0;
				q1.push({ i,j });
			}
			else if (arr[i][j] == '@') {
				time2[i][j] = 0;
				q2.push({ i,j });
			}
		}
	}

	while (!q1.empty()) { // 불
		pair<int, int>cur = q1.front();
		q1.pop();
		for (int dir = 0; dir < 4; dir++) {
			int mx = cur.first + dx[dir];
			int my = cur.second + dy[dir];
			if (mx < 0 || my < 0 || mx >= h || my >= w)
				continue;
			if (arr[mx][my] == '#' || time1[mx][my] >= 0)
				continue;
			time1[mx][my] = time1[cur.first][cur.second] + 1;
			q1.push({ mx,my });
		}
	}

	while (!q2.empty()) { //상근이
		pair<int, int>cur = q2.front();
		q2.pop();
		for (int dir = 0; dir < 4; dir++) {
			int mx = cur.first + dx[dir];
			int my = cur.second + dy[dir];
			if (mx < 0 || my < 0 || mx >= h || my >= w) {
				cout << time2[cur.first][cur.second] + 1;
				return;
			}
			if (arr[mx][my] == '#' || time2[mx][my] >= 0)
				continue;
			if (time1[mx][my] != -1 && time1[mx][my] <= time2[cur.first][cur.second] + 1)
				continue;
			time2[mx][my] = time2[cur.first][cur.second] + 1;
			q2.push({ mx,my });
		}
	}
	cout << "IMPOSSIBLE";
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int test;
	cin >> test;
	for (int x = 0; x < test; x++) {
		bfs();
		cout << '\n';
	}
}