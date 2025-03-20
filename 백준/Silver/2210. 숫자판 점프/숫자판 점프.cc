#include <bits/stdc++.h>
using namespace std;

typedef struct {
    int x;
    int y;
    int cnt;
    string s;
} st;

int arr[5][5];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int chk[1000000];
// queue<pair<int,int>>q;
queue<st> q;
set<string>mySet;
vector<string>v;
int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for(int i=0;i<5;i++) {
        for(int j=0;j<5;j++) {
            cin>>arr[i][j];
        }
    }
    int count = 0;
    for(int i=0;i<5;i++) {
        for(int j=0;j<5;j++) {
            string s;
            s += to_string(arr[i][j]);
            q.push({i,j, 1, s});

        }
    }
    while (!q.empty()) {
        st p = q.front();
        q.pop();
        if (p.cnt == 6) {
            string cur = p.s;
            int cur_int = stoi(cur);
            if (chk[cur_int] == 0) {
                chk[cur_int] = 1;
                count+=1;
            }
            continue;
        }
        for(int k=0;k<4;k++) {
            int mx = p.x + dx[k];
            int my = p.y + dy[k];
            if (mx<0 || mx>=5 || my<0 || my>=5)
                continue;
            string cur = p.s;
            cur += to_string(arr[mx][my]);
            q.push({mx,my, p.cnt + 1, cur});
        }
    }


    cout<<count<<endl;
}


