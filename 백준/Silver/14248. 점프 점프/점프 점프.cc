#include<bits/stdc++.h>
using namespace std;

int arr[100001];
bool visited[100001];


void bfs(int start, int size) {
    queue<int>q;
    q.push(start);
    visited[start] = true;

    while(!q.empty()) {
        int curr = q.front(); // 현재 인덱스
        q.pop();

        int nextIndex;

        for (int i=0;i<2;i++) {
            if (i==0)
                nextIndex = curr+arr[curr];
            else
                nextIndex = curr - arr[curr];

            if (nextIndex<1 || nextIndex>size)
                continue;
            if (visited[nextIndex])
                continue;
            q.push(nextIndex);
            visited[nextIndex] = true;

        }
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,start,ans=0;
    cin>>n;

    for (int i=1;i<=n;i++)
        cin>>arr[i];

    cin>>start;
    bfs(start,n);

    for (int i=1;i<=n;i++) {
        if (visited[i])
            ans++;
    }

    bfs(start,n);
    cout<<ans;
}