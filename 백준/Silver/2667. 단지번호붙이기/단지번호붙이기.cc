#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
char arr[26][26];
int vis[26][26];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for (int x = 0; x < n; x++) {
		for (int y = 0; y < n; y++) {
			cin >> arr[x][y];
		}
	}
	queue<pair<int, int>>q;
	int num = 0;
	vector<int>res;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == '0' || vis[i][j])
				continue;
			q.push({ i,j });
			vis[i][j] = 1;
			num++;
			int area = 0;
			while (!q.empty()) {
				area++;
				pair<int, int>cur = q.front();
				q.pop();
				for (int x = 0; x < 4; x++) {
					int mx = cur.first + dx[x];
					int my = cur.second + dy[x];
					if (mx < 0 || my < 0 || mx >= n || my >= n)
						continue;
					if (arr[mx][my] == '0' || vis[mx][my])
						continue;
					vis[mx][my] = 1;
					q.push({ mx,my });
				}
			}
			res.push_back(area);
		}
	}
	sort(res.begin(), res.end());
	cout << num << endl;
	for (int x = 0; x < res.size(); x++)
		cout << res[x] << endl;
}