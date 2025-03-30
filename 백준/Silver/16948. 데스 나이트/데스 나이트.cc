#include<bits/stdc++.h>
using namespace std;

int arr[201][201];
int dx[6] = {-2, -2, 0, 0, 2, 2};
int dy[6] = {-1, 1, -2, 2, -1, 1};
bool visited[201][201];
queue<pair<int, int> > q;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, r1, c1, r2, c2;
    cin >> n;
    cin >> r1 >> c1 >> r2 >> c2;

    visited[r1][c1] = true;
    q.push({r1, c1});

    while (!q.empty()) {
        pair<int, int> p = q.front();
        q.pop();
        for (int i = 0; i < 6; i++) {
            int nr = p.first + dx[i];
            int nc = p.second + dy[i];
            if (nr < 0 || nr >= n || nc < 0 || nc >= n)
                continue;
            if (nr == r2 && nc == c2) {
                cout << arr[p.first][p.second] + 1;
                return 0;
            }
            if (visited[nr][nc])
                continue;
            arr[nr][nc] = arr[p.first][p.second] + 1;
            visited[nr][nc] = true;
            q.push({nr, nc});
        }
    }

    cout << -1;
}