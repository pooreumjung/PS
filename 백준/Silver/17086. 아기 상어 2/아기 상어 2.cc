#include<bits/stdc++.h>
using namespace std;

int arr[51][51];
bool visited[51][51];
int dx[8]={-1,-1,-1,0,1,1,1,0};
int dy[8]={-1,0,1,1,1,0,-1,-1};

typedef struct {
    int x;
    int y;
    int count;
}st ;

int bfs(int i,int j,int n,int m) {
    queue<st> q;
    q.push({i,j,0});
    visited[i][j] = true;

    int count = 100;

    while(!q.empty()) {
        st cur = q.front();
        q.pop();
        for(int k=0;k<8;k++) {
            int nx = cur.x+dx[k];
            int ny = cur.y+dy[k];

            if (nx<0 ||nx>=n || ny<0 || ny>=m )
                continue;
            if (visited[nx][ny])
                continue;
            if (arr[nx][ny]==1) {
                if (cur.count+1 < count)
                    count = cur.count+1;
                continue;
            }
            visited[nx][ny] = true;
            q.push({nx,ny,cur.count+1});
        }
    }

    memset(visited,false,sizeof(visited));
    return count;

}
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m,max=-1;
    cin>>n>>m;

    queue<pair<int,int>>startQueue;

    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin>>arr[i][j];
            if(arr[i][j]==0)
                startQueue.push(make_pair(i,j));
        }
    }

    while(!startQueue.empty()) {
        pair<int,int> p = startQueue.front();
        startQueue.pop();
        int ans = bfs(p.first, p.second,n,m);
        if (ans>max)
            max=ans;
    }

    cout<<max;
}