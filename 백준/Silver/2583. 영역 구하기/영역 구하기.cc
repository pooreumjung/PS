#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;
queue<pair<int, int>>q;
vector<int>v;
int arr[101][101];
bool vis[101][101];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int bfs(int m,int n) {
	int number = 0,area=0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == 1 || vis[i][j])
				continue;
			area = 0;
			q.push({ i,j });
			vis[i][j] = true;
			number++;
			while (!q.empty()) {
				area++;
				pair<int, int>cur = q.front();
				q.pop();
				for (int k = 0; k < 4; k++) {
					int mx = cur.first + dx[k];
					int my = cur.second + dy[k];
					if (mx < 0 || my < 0 || mx >= m || my >= n)
						continue;
					if (arr[mx][my] == 1 || vis[mx][my])
						continue;
					q.push({ mx,my });
					vis[mx][my] = true;
				}			
			}
			v.push_back(area);
		}
	}
	return number;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int m, n, k;
	cin >> m >> n >> k;
	for (int i = 0; i < k; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		for (int j = x1; j <x2; j++) {
			for (int k = m-y2; k <m- y1; k++) {
				arr[k][j] = 1;
			}
		}
	}
	int number=bfs(m,n);
	sort(v.begin(), v.end());
	cout << number << endl;
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ";
}