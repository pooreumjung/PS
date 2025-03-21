#include <bits/stdc++.h>
using namespace std;

typedef struct {
    int cur_x;
    int cur_y;
    int cur_value; // 움직여야 하는 거리
} st;

queue<st> q;
int arr[10][10];
bool visited[10][10];
int dx[2] = {1,0};
int dy[2] = {0,1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    q.push({0,0,arr[0][0]});
    visited[0][0] = true;
    bool check = false;

    while (!q.empty()) {
        st temp = q.front();
        q.pop();
        for (int i = 0; i < 2; i++) {
            int mx = temp.cur_x + temp.cur_value*dx[i];
            int my = temp.cur_y + temp.cur_value*dy[i];
            if (mx<0 || mx>=n || my<0 || my>=n)
                continue;
            if (visited[mx][my])
                continue;
            visited[mx][my] = true;
            q.push({mx, my, arr[mx][my]});
        }
    }

    if (visited[n-1][n-1])
        cout<<"HaruHaru";
    else
        cout<<"Hing";
}