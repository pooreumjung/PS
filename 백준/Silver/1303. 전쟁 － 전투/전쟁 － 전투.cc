#include<bits/stdc++.h>
using namespace std;

char arr[101][101];
bool visited[101][101];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, wCount=0, bCount=0;
    cin >> m>>n;

    for (int i = 0; i < n; i++) {
        for (int j=0; j<m; j++) {
            cin >> arr[i][j];
        }
    }


    for (int i = 0; i < n; i++) {
        for (int j=0; j<m; j++) {
            if (!visited[i][j]) {
                queue<pair<int,int>>q;
                q.push(make_pair(i,j));
                visited[i][j] = true;
                int area = 1;
                char start = arr[i][j];
                while (!q.empty()) {
                    pair<int,int>cur = q.front();
                    q.pop();

                    for (int k = 0; k < 4; k++) {
                        int nx = cur.first + dx[k];
                        int ny = cur.second + dy[k];

                        if (nx <0 || nx >= n || ny <0 || ny >= m)
                            continue;
                        if (visited[nx][ny] || arr[nx][ny] != start)
                            continue;
                        visited[nx][ny] = true;
                        q.push(make_pair(nx,ny));
                        area++;
                    }
                }
                if (start == 'B')
                    bCount += area * area;
                else
                    wCount += area * area;
            }
        }
    }
    cout << wCount << " "<<bCount;
}