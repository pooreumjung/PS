#include<iostream>
#include<queue>
using namespace std;
char arr[31][31][31];
int time1[31][31][31];
bool vis[31][31][31];
int dir[6][3] = {
	{1,0,0},
	{-1,0,0},
	{0,1,0},
	{0,-1,0},
	{0,0,-1},
	{0,0,1}
};
void clear() {
	for (int i = 0; i < 31; i++) {
		for (int j = 0; j < 31; j++) {
			for (int k = 0; k < 31; k++) {
				time1[i][j][k] = -1;
				vis[i][j][k] = false;
			}
		}
	}
}
void bfs(int l, int r, int c) {
	int  flag = 0;
	queue<pair<int, pair<int, int>>>q;
	for (int i = 0; i < l; i++) {
		for (int j = 0; j < r; j++) {
			for (int k = 0; k < c; k++) {
				cin >> arr[i][j][k];
				if (arr[i][j][k] == 'S') {
					q.push({ i,{j ,k} });
					vis[i][j][k] = true;
					time1[i][j][k] = 0;
				}
			}
		}
	}
	while (!q.empty()) {
		int x1 = q.front().first;
		int y1 = q.front().second.first;
		int z1 = q.front().second.second;
		q.pop();
		for (int x = 0; x < 6; x++) {
			int mx = x1 + dir[x][0];
			int my = y1 + dir[x][1];
			int mz = z1 + dir[x][2];
			if (mx < 0 || my < 0 || mz < 0 || mx >= l || my >= r || mz >= c)
				continue;
			if (time1[mx][my][mz] >= 0 || vis[mx][my][mz] || arr[mx][my][mz] == '#')
				continue;
			if (arr[mx][my][mz] == 'E') {
				flag = 1;
				cout << "Escaped in " << time1[x1][y1][z1] + 1 << " minute(s)." << '\n';
			}
			q.push({ mx,{my,mz} });
			vis[mx][my][mz] = true;
			time1[mx][my][mz] = time1[x1][y1][z1] + 1;
		}
	}
	if (flag == 1)
		return;
	else {
		cout << "Trapped!" << '\n';
		return;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	while (true) {
		clear();
		int l, r, c;
		cin >> l >> r >> c;
		if (l == 0 && r == 0 && c == 0)
			break;
		bfs(l, r, c);
	}

}