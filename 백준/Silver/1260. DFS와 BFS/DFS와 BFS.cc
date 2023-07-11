#include<iostream>
using namespace std;
int arr[1001][1001];
int map[1001];
int used[1001];
int used2[1001];
int n, m, start;
int head = 0, tail = 1;
struct node {
	int num, level;
};
node que[1001];
void dfs(int dx);
int main() {
	cin >> n >> m >> start;
	for (int x = 0; x < m; x++) {
		int a, b;
		cin >> a >> b;
		arr[a][b] = 1;
		arr[b][a] = 1;
	}
	int startindex = 0;
	for (int x = 0; x < n; x++)
		map[x] = x + 1;
	used[start] = 1;
	dfs(start);
	cout << endl;
	que[0] = { start,0 };
	used2[start] = 1;
	cout << start << " ";
	while (head != tail) {
		node now = que[head];
		for (int x = 0; x <=n; x++) {
			if (arr[now.num][x] == 1 && used2[x] == 0) {
				cout << x << " ";
				que[tail++] = { x,now.level + 1 };
				used2[x] = 1;
			}
		
		}
		head++;

	}
}
void dfs(int now) {
	cout << now << " ";
	for (int x = 0; x <= n; x++) {
		if (arr[now][x] == 1&&used[x]==0) {
			used[x] = 1;
			dfs(x);
		}
	}
}
