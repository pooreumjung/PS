#include<bits/stdc++.h>
using namespace std;

string arr[1001];
bool visited[1001][1001];

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

bool bfs(int i,int j,int m,int n) {
    queue<pair<int,int> > q;
    q.push({i,j});
    visited[i][j] = true;

    while(!q.empty()) {
        pair<int,int> p = q.front();
        q.pop();

        for(int k=0;k<4;k++) {
            int nx = p.first+dx[k];
            int ny = p.second+dy[k];

            if (nx<0 || ny<0 || ny >=n)
                continue;
            if (nx>=m)
                return true;
            if (visited[nx][ny] || arr[nx][ny] == '1')
                continue;
            visited[nx][ny] = true;
            q.push({nx,ny});
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m, n;
    cin >> m >> n;

    for (int i = 0; i < m; i++) {
        cin >> arr[i];
    }

    bool flag = false;

    for (int j = 0; j < n; j++) {
        if (arr[0][j] == '0') {
            flag = bfs(0,j,m,n);
            if (flag)
                break;
            memset(visited,false,sizeof(visited));
        }
    }

    if (flag)
        cout<<"YES";
    else
        cout<<"NO";
}