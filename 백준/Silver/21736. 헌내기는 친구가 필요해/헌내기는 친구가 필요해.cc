#include <bits/stdc++.h>
using namespace std;

char arr[601][601];
bool check[601][601];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
queue<pair<int,int>> q;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m,count=0;
    cin>>n>>m;

    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin>>arr[i][j];

            // 도연이의 위치 저장
            if (arr[i][j] == 'I') {
                q.push(make_pair(i,j));
                check[i][j] = true;
            }
        }
    }
    
    while (!q.empty()) {
        pair<int,int> p = q.front();
        q.pop();
        for(int i=0;i<4;i++) {
            int mx = p.first + dx[i];
            int my = p.second + dy[i];
            if (mx < 0 || mx >= n || my < 0 || my >= m)
                continue;
            if (arr[mx][my] == 'X' || check[mx][my])
                continue;
            check[mx][my] = true;
            if (arr[mx][my] == 'P')
                count++;
            q.push(make_pair(mx,my));
        }
    }

    if (count)
        cout<<count;
    else
        cout<<"TT";
}