#include<iostream>
#include<queue>
using namespace std;

int arr[1001][1001];
int dist[1001][1001];
bool visit[1001][1001];
int dx[4] = { 0,1,-1,0 };
int dy[4] = { 1,0 ,0,-1 };

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	int index1 = 0, index2 = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 2) {
				index1 = i;
				index2 = j;
			}
			if (arr[i][j] != 0)
				dist[i][j] = -1;
		}
	}

	dist[index1][index2] = 0;
	visit[index1][index2] = true;

	queue<pair<int, int>>myqueue;
	myqueue.push({ index1,index2 });

	while (!myqueue.empty()) {
		pair<int, int>cur = myqueue.front();
		myqueue.pop();
		for (int i = 0; i < 4; i++) {
			int mx = cur.first + dx[i];
			int my = cur.second + dy[i];
			if (mx < 0 || my < 0 || mx >= n || my >= m)
				continue;
			if (arr[mx][my] == 0 || visit[mx][my])
				continue;
			visit[mx][my] = true;
			myqueue.push({ mx,my });
			dist[mx][my] = dist[cur.first][cur.second] + 1;
		}
	}

	dist[index1][index2] = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << dist[i][j] << " ";
		}
		cout << '\n';
	}

}