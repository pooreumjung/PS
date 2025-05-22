#include<iostream>
#include<queue>
#include<vector>
using namespace std;

typedef pair<int, int>cur;
int area[101][101];
int dist[101][101];
bool visit[101][101];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int N,now;
void bfs(int i, int j);
int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> area[i][j];
			dist[i][j] = -1;
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (visit[i][j] == false && area[i][j] == 1) {
				now++;
				bfs(i, j);
			}
		}
	}

	int min_val = 987654321;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (area[i][j] == 0)
				continue;
			for (int ll = 0; ll < N; ll++) {
				for (int jj = 0; jj < N; jj++)
					dist[ll][jj] = -1;
			}

			queue<cur>q;
			q.push({ i,j });
			dist[i][j] = 0;
			int now_m = area[i][j];

			while (!q.empty()) {
				cur tmp = q.front();
				int x1 = tmp.first;
				int y1 = tmp.second;
				q.pop();

				for (int k = 0; k < 4; k++) {
					int mx = x1 + dx[k];
					int my = y1 + dy[k];
					if (mx < 0 || my < 0 || mx >= N || my >= N)
						continue;
					if (dist[mx][my] != -1)
						continue;
					if (area[mx][my] == now_m)
						continue;
					if (area[mx][my] != 0)
						min_val = min(min_val, dist[x1][y1]);
					else {
						dist[mx][my] = dist[x1][y1] + 1;
						q.push({ mx,my });
					}
				}
			}

		}
	}
	cout << min_val;
}
void bfs(int i, int j) {

	queue<cur>q;
	q.push({ i,j });
	visit[i][j] = true;
	area[i][j] = now;

	while (!q.empty()) {

		cur tmp = q.front();
		int x1 = tmp.first;
		int y1 = tmp.second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int mx = x1 + dx[i];
			int my= y1 + dy[i];

			if (mx < 0 || my < 0 || mx >= N || my >= N)
				continue;
			if (area[mx][my] == 0 || visit[mx][my])
				continue;
			area[mx][my] = now;
			q.push({ mx,my });
			visit[mx][my] = true;
		}
	}
}