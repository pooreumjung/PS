#include<iostream>
#include<queue>
using namespace std;
int arr[51][51];
int check[51][51];
int dx[8] = { 1,1,1,0,0,-1,-1,-1 };
int dy[8] = { 0,1,-1,1,-1,0,1,-1 };
int bfs(int b,int a) {
	queue<pair<int, int>>q;
	int area = 0;
	for (int x = 0; x < b; x++) {
		for (int y = 0; y < a; y++) {
			if (check[x][y] || arr[x][y] == 0)
				continue;
			area++;
			q.push({ x,y });
			check[x][y] = 1;
			while (!q.empty()) {
				pair<int, int>cur = q.front();
				q.pop();
				for (int x = 0; x < 8; x++) {
					int mx = cur.first + dx[x];
					int my = cur.second + dy[x];
					if (mx < 0 || my < 0 || mx >= b || my >= a)
						continue;
					if (arr[mx][my] == 0 || check[mx][my])
						continue;
					q.push({ mx,my });
					check[mx][my] = 1;

				}

			}

		}
	}
	for (int x = 0; x < b; x++) {
		for (int y = 0; y < a; y++) {
			arr[x][y] = 0;
			check[x][y] = 0;
		}
	}
	return area;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	while (1) {
		int a, b;
		cin >> a >> b;
		if (a == 0 && b == 0)
			break;
		for (int x = 0; x < b; x++) {
			for (int y = 0; y < a; y++)
				cin >> arr[x][y];
		}
		int c = bfs(b,a);
		cout << c << endl;
	}
	
}