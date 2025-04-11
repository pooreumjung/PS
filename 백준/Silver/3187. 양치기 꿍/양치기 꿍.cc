#include<bits/stdc++.h>
using namespace std;

typedef struct {
    int v;
    int k;
}st;
char house[251][251];
bool visited[251][251];
queue<st>resultQueue;

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int r,c;
    cin>>r>>c;

    for(int i=0;i<r;i++) {
        for(int j=0;j<c;j++) {
            cin>>house[i][j];
        }
    }

    for (int i=0;i<r;i++) {
        for (int j=0;j<c;j++) {
            if (house[i][j]!='#' && !visited[i][j]) {
                queue<pair<int,int>>q;
                q.push({i,j});
                visited[i][j]=true;
                st s;
                s.v=0;
                s.k=0;
                if(house[i][j]=='v')
                    s.v++;
                else if(house[i][j]=='k')
                    s.k++;
                while (!q.empty()) {
                    pair<int,int>cur=q.front();
                    q.pop();

                    for (int k=0;k<4;k++) {
                        int nx=cur.first+dx[k];
                        int ny=cur.second+dy[k];
                        if (nx <0 || ny <0 || nx>=r || ny>=c)
                            continue;
                        if (house[nx][ny]=='#' || visited[nx][ny])
                            continue;
                        q.push({nx,ny});
                        visited[nx][ny]=true;
                        if (house[nx][ny] == 'v')
                            s.v++;
                        else if (house[nx][ny] == 'k')
                            s.k++;
                    }
                }
                resultQueue.push(s);
            }
        }
    }

    int vCount=0, kCount=0;
    while (!resultQueue.empty()) {
        st s = resultQueue.front();
        resultQueue.pop();
        if (s.k > s.v)
            kCount += s.k;
        else
            vCount += s.v;
    }

    cout<<kCount<<" "<<vCount;
}