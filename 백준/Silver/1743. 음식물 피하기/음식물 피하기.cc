#include<iostream>
#include<queue>
using namespace std;

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int arr[101][101];
bool visit[101][101];
int N, M, T;
int MAX = 0;
queue<pair<int, int>>myqueue;
void bfs();

int main() {

	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	
	int max = 0;
	cin >> N >> M>>T;

	for (int i = 0; i < T; i++) {
		int s, e;
		cin >> s >> e;
		arr[s][e] = 1;
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (arr[i][j] == 1 && visit[i][j] == false) {
				myqueue.push({ i,j });
				visit[i][j] = true;
				bfs();
			}
			
		}
	}
	cout << MAX;
}

void bfs() {
	int Count = 0;
	while (!myqueue.empty()) {
		pair<int, int>cur = myqueue.front();
		myqueue.pop();
		Count++;
		for (int k = 0; k < 4; k++) {
			int mx = cur.first + dx[k];
			int my = cur.second + dy[k];
			if (mx < 1 || my <1 || mx > N || my > M)
				continue;
			if (arr[mx][my] == 0 || visit[mx][my])
				continue;
			visit[mx][my] = true;
			myqueue.push({ mx,my });
		}
	}
	if (Count > MAX)
		MAX = Count;
}