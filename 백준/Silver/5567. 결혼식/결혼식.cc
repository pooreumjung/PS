#include<bits/stdc++.h>
using namespace std;

vector<vector<int> > adj;
vector<bool> visited;
int ans = 0;

void dfs(int start) {
    visited[start] = true;
    queue<pair<int,int>>q;
    q.push({start,0});

    while (!q.empty()) {
        pair<int,int> cur = q.front();
        q.pop();

        for (int next: adj[cur.first]) {
            if (visited[next])
                continue;
            if (cur.second==2)
                continue;
            visited[next] = true;
            q.push({next,cur.second+1});
            ans++;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    adj.resize(n + 1);
    visited.resize(n + 1, false);

    for (int i = 0; i < m; i++) {
        int node1, node2;
        cin >> node1 >> node2;

        adj[node1].push_back(node2);
        adj[node2].push_back(node1);
    }

    dfs(1);
    cout << ans;
}