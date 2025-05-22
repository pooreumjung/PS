#include<iostream>
#include<queue>
using namespace std;

int dx[8] = { 1,0,-1,0,1,1,-1,-1 };
int dy[8] = { 0,1,0,-1,1,-1,1,-1 };

int arr[251][251];
bool visit[251][251];
queue<pair<int, int>>myqueue;

int main() {

	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int N, M;
	int result = 0;
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
			cin >> arr[i][j];
	}

	

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] == 1 && visit[i][j] == false) {
				result++;
				myqueue.push({ i,j });
				visit[i][j] = true;
			}
			while (!myqueue.empty()) {
				pair<int, int>cur = myqueue.front();
				myqueue.pop();
				for (int k = 0; k < 8; k++) {
					int mx = cur.first + dx[k];
					int my = cur.second + dy[k];
					if (mx < 0 || my < 0 || mx >= N || my >= M)
						continue;
					if (arr[mx][my] == 0 || visit[mx][my])
						continue;
					visit[mx][my] = true;
					myqueue.push({ mx,my });
				}

			}
		}
	}
	cout << result;
}