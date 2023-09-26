#include <iostream>
#include <string>
#include <queue>
using namespace std;

int n, m, k;
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
int arr[1001][1001];
int vis[1001][1001][11];

int bfs() {
    queue<pair<pair<int, int>, int>> q;
    q.push(make_pair(make_pair(0, 0), 0));
    vis[0][0][0] = 1;

    while (!q.empty()) {
        int mx = q.front().first.first;
        int my = q.front().first.second;
        int mz = q.front().second;
        q.pop();

        if (mx == m - 1 && my == n - 1)
            return vis[my][mx][mz];

        for (int i = 0; i < 4; i++) {
            int fx = mx + dx[i];
            int fy = my + dy[i];

            if (fx >= 0 && fx <= m - 1 && fy >= 0 && fy <= n - 1) {
                if (mz < k && arr[fy][fx] == 1 && vis[fy][fx][mz + 1] == 0) {
                    vis[fy][fx][mz + 1] = vis[my][mx][mz] + 1;
                    q.push(make_pair(make_pair(fx, fy), mz + 1));
                }
                else if (arr[fy][fx] == 0 && vis[fy][fx][mz] == 0) {
                    vis[fy][fx][mz] = vis[my][mx][mz] + 1;
                    q.push(make_pair(make_pair(fx, fy), mz));
                }
            }

        }
    }
    return -1;
}

int main() {
    scanf("%d %d %d", &n, &m, &k);

    for (int i = 0; i < n; i++) {
        string temp;
        cin >> temp;
        for (int j = 0; j < m; j++)
            arr[i][j] = temp[j] - '0';
    }

    printf("%d\n", bfs());
}