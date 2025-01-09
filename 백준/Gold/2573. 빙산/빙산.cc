#include<bits//stdc++.h>
using namespace std;

int arr[301][301];
int arr2[301][301];
bool visited[301][301];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
// 0이 아닌 곳 중 하나를 시작점으로 넣어서 탐색

int bfs(int n, int m) {

    queue<pair<int,int>>q;
    int count=0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(arr[i][j] ==0 || visited[i][j])
                continue;
            q.push({ i,j });

            visited[i][j]=true;
            count++;
            while (!q.empty()) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for(int k=0;k<4;k++) {
                    int mx = x+dx[k];
                    int my = y+dy[k];
                    if (mx<0 || mx>=n || my<0 || my>=m)
                        continue;
                    if(arr[mx][my] == 0 || visited[mx][my])
                        continue;
                    visited[mx][my]=true;
                    q.push({ mx,my });
                }
            }
        }
    }

    for (int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            visited[i][j]=false;
        }
    }
    return count;
}

void copyArrToArr2(int n,int m) {
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            arr2[i][j]=arr[i][j];
        }
    }
}
void updateArr(int n,int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j]) {
                if (j-1 >=0 && j-1<m ) { // 범위 안에 들어갈 때
                    if (arr[i][j-1] == 0 && arr[i][j]>0 && arr2[i][j-1] == 0)
                        arr[i][j] -= 1;
                }
                else { // 범위 밖에 있을 때
                    if ( arr[i][j]>0)
                        arr[i][j] -= 1;
                }

                if (j+1 >=0 && j+1<m) { // 범위 안에 들어갈 때
                    if (arr[i][j+1] == 0 &&  arr[i][j]>0 && arr2[i][j+1] == 0)
                        arr[i][j] -= 1;
                }
                else { // 범위 밖에 있을 때
                    if (arr[i][j]>0)
                        arr[i][j] -= 1;
                }

                if (i-1 >=0 && i-1<n) { // 범위 안에 들어갈 때
                    if (arr[i-1][j] == 0 && arr[i][j]>0 && arr2[i-1][j] == 0)
                        arr[i][j] -= 1;
                }
                else { // 범위 밖에 있을 때
                    if (arr[i][j]>0)
                        arr[i][j] -= 1;
                }

                if (i+1 >=0 &&  i+1<n) { // 범위 안에 들어갈 때
                    if (arr[i+1][j] == 0 && arr[i][j]>0 && arr2[i+1][j] == 0)
                        arr[i][j] -= 1;
                }
                else { // 범위 밖에 있을 때
                    if (arr[i][j]>0)
                        arr[i][j] -= 1;
                }
            }

        }
    }

}
// false면 모두녹은 것임
bool checkArr(int n,int m) {
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            if (arr[i][j] != 0)
                return true;
        }
    }
    return false;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;
    cin>>n>>m;

    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            arr2[i][j]=-1;
        }
    }
    // 입력 받기
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin>>arr[i][j];
        }
    }
    int count = 0;
    copyArrToArr2(n,m);
    while(true) {
        int result = bfs(n,m);
        if(result>=2) {
            cout<<count<<"\n";
            break;
        }
        copyArrToArr2(n,m);
        updateArr(n,m);
        bool check = checkArr(n,m);
        if (check == false) {
            if (count == 0) {
                cout<<1;
            }
            else
                cout<<0;
            break;
        }
        count++;
    }
}


// 1. 입력받기
// 2. for문을 돌리면서 arr배열 업데이트
// 3. bfs탐색으로 덩어리가 나뉘어지는지를 탐색
// 2~3의 과정을 반복하다가 3을 만족하는 순간 finish

// 시간 복잡도
// 2중 for문 => 300의 제곱 => 90000
// bfs는 o(v+e) => 그러면 300의 3제곱 270000