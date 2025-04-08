#include<bits/stdc++.h>
using namespace std;

bool isVisited[1001];
int graph[1001];

void dfs(int cur) {
    if (isVisited[cur])
        return;
    isVisited[cur] = true;
    dfs(graph[cur]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin>>t;

    while (t--) {
        int N,ans=0;
        cin>>N;

        memset(isVisited, false, sizeof(isVisited));

        for (int i = 1; i <= N; ++i)
        {
            cin >> graph[i];
        }

        for (int i = 1; i <= N; i++) {
            if (isVisited[i])
                continue;
            dfs(i);
            ans++;
        }
        cout<<ans<<'\n';
    }
}