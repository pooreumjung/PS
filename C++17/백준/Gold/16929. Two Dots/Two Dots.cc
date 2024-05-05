#include<iostream>
#include<vector>
#include<queue>
using namespace std;

typedef pair<int, int>edge;
char map[51][51];
bool visit[51][51];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int N, M;
bool check = false;
int start_X = 0;
int start_Y = 0;

void dfs(int i, int j,int cnt);
int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			start_X = i;
			start_Y = j;
			dfs(i, j,1);
			if (check) {
				cout << "Yes";
				return 0;
			}
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < M; j++) {
					visit[i][j]=false;
				}
			}
		}
	}
	cout << "No";
}
void dfs(int i, int j,int cnt) {

	if (check)
		return;
	visit[i][j] = true;
	
	for (int x = 0; x < 4; x++) {
		int mx = dx[x] + i;
		int my = dy[x] + j;
		if (mx < 0 || my < 0 || mx >= N || my >= M)
			continue;
		if (map[mx][my] != map[i][j])
			continue;
		if (visit[mx][my] == false) {
			visit[mx][my] = true;
			dfs(mx, my, cnt + 1);
		}
		else {
			if (cnt >= 4 && mx == start_X && my == start_Y) {
				check = true;
				return;
			}
		}
	}


}




//bool bfs(int i, int j)
//{
//	queue<edge>q;
//	q.push({ i,j });
//	visit[i][j] = true;
//	char ch = map[i][j];
//	bool flag = false;
//	int k = 1;
//
//	while (!q.empty()) {
//		edge cur = q.front();
//		k++;
//		q.pop();
//		for (int x = 0; x < 4; x++) {
//			int mx = dx[x] + cur.first;
//			int my = dy[x] + cur.second;
//			if (mx < 0 || my < 0 || mx >= N || my >= M)
//				continue;
//			if (map[mx][my] != ch)
//				continue;
//
//			if (visit[mx][my] == false) {
//				visit[mx][my] = true;
//				q.push({ mx,my });
//			}
//
//			else
//			{
//				if (k >= 4 && mx == i && my == j)
//					return true;
//			}
//		}
//	}
//		
//}
