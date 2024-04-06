#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
#define INF 100001

int n, m, u, v, cost;
int map[101][101];
int route[101][101];
vector<int>path;
void pathfind(int start, int end);
int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	for(int i=1;i<=n;i++){
		for (int j = 1; j <= n; j++) {
			if (i == j)
				map[i][j] = 0;
			else
				map[i][j] = INF;
		}
	}

	while (m--) {
		cin >> u >> v >> cost;
		map[u][v] = min(map[u][v], cost);
		route[u][v] = u;
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (map[i][j] > map[i][k] + map[k][j]) {
					map[i][j] = map[i][k] + map[k][j];
					route[i][j] = route[k][j];
				}
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (map[i][j] == INF)
				cout << 0 << " ";
			else
				cout << map[i][j] << " ";
		}
		cout << '\n';
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j)
				cout << 0 << "\n";
			else {
				pathfind(i, j);
				if (path.empty() && map[i][j] == INF)
					cout << 0 << " ";
				else {
					cout << path.size()+1 << " ";
					for (int i = 0; i < path.size(); i++) {
						cout << path[path.size() - i - 1] << " ";
					}
					cout << j << " ";
				}
				cout << '\n';
			}
			path.clear();
		}
	}
}
void pathfind(int start, int end) {
	int s = route[start][end];
	while (s != 0) {
		path.push_back(s);
		s = route[start][s];
	}
}