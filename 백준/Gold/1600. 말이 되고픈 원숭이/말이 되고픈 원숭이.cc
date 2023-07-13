#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int K, W, H;
int map[201][201];
int c[201][201][31];

int hx[] = { -2,-1,1,2,2,1,-1,-2 };
int hy[] = { -1,-2,-2,-1,1,2,2,1 };
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };

void Bfs(int s1, int s2, int s3) {
	queue<tuple<int, int,int>> q;
	q.push(make_tuple(s1, s2, s3));
	c[s1][s2][s3] = 1;

	while (!q.empty()) {
		int x = get<0>(q.front());
		int y = get<1>(q.front());
		int jump = get<2>(q.front());
		q.pop();
		if (x == H && y == W) {
			cout << c[x][y][jump] - 1;
			return;
		}
		if (jump < K) {
			for (int i = 0; i < 8; i++) {
				int nx = x + hx[i];
				int	ny = y + hy[i];
				if (nx < 1 || nx > H || ny < 1 || ny > W) continue;
				if(!c[nx][ny][jump+1] && map[nx][ny] == 0) {
					c[nx][ny][jump+1] = c[x][y][jump] + 1;
					q.push(make_tuple(nx, ny, jump + 1));
				}
			}
		}
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 1 || nx > H || ny < 1 || ny > W) continue;
			if (!c[nx][ny][jump] && map[nx][ny] == 0)
			{
				c[nx][ny][jump] = c[x][y][jump] + 1;
				q.push(make_tuple(nx, ny, jump));
			}
		}
	}
	cout << "-1";
	return;
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> K >> W >> H;

	for (int i = 1; i <= H; i++)
		for (int j = 1; j <= W; j++) cin >> map[i][j];

	Bfs(1, 1, 0);
}