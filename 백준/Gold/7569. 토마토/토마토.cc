#include<iostream>
#include<queue>
#include<vector>
using namespace std;
vector<vector<int>> dir = { {-1,0,0}, {1,0,0}, {0,1,0}, {0,-1,0}, {0,0,1}, {0,0,-1} };
queue<pair<int, pair<int, int>>>q;
int arr[101][101][101];
bool vis[101][101][101];
int time1[101][101][101];
int bfs(int M, int N, int H) {


	while (!q.empty()) {
		pair<int, pair<int, int>>cur = q.front();
		q.pop();
		for (int x = 0; x < 6; x++) {
			int mx = cur.first + dir[x][0];
			int my = cur.second.first + dir[x][1];
			int mz = cur.second.second + dir[x][2];
			if (mx < 0 || my < 0 || mz < 0 || mx >= H || my >= N || mz >= M) //범위를 벗어날 때
				continue;
			if (time1[mx][my][mz] >= 0)
				continue;
			if (arr[mx][my][mz] == 0) {
				q.push({ mx,{my,mz} });
				time1[mx][my][mz] = time1[cur.first][cur.second.first][cur.second.second] + 1;
				arr[mx][my][mz] = 1; // 토마토가 익었음
			}
		}
	}




	int max = -1;
	for (int i = 0; i < H; i++) { // 걸린 시간 찾기
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++)
			{
				if (max < time1[i][j][k])
					max = time1[i][j][k];
			}
		}
	}
	for (int i = 0; i < H; i++) { // 걸린 시간 찾기
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++)
			{
				if (arr[i][j][k] == 0)
					return -1;
			}
		}
	}

	return max;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++) {
			for (int k = 0; k < 101; k++)
				time1[i][j][k] = -1;
		}
	}
	int M, N, H;
	cin >> M >> N >> H;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				cin >> arr[i][j][k];
				if (arr[i][j][k] == 1) {
					q.push({ i,{j,k} });
					time1[i][j][k] = 0;
				}
			}
		}
	}
	cout << bfs(M, N, H);

}