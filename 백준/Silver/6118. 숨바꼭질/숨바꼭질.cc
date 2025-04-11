#include<bits/stdc++.h>
using namespace std;

vector<vector<int> > adj;
vector<int> level;
vector<bool> visited;
set<int> s;

void bfs(int node) {
    queue<pair<int,int>>q;
    q.push({node,0});

    visited[node] = true;
    level[node] = 0;

    while (!q.empty()) {
        pair<int,int> p = q.front();
        q.pop();

        for (int next:adj[p.first]) {
            if (!visited[next]) {
                level[next] = level[p.first] + 1;
                q.push({next,level[next]});
                visited[next] = true;
            }
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
    level.resize(n + 1, 0);

    for (int i = 0; i < m; i++) {
        int node1, node2;
        cin >> node1 >> node2;

        adj[node1].push_back(node2);
        adj[node2].push_back(node1);
    }

    bfs(1);

    int num,length,count=0, max=-1;

    for (int i = 2; i <= n; i++) {
        if (level[i] > max) {
            num = i; // 숨어야 하는 헛간번호
            length = level[i]; // 헛간까지의 거리
            count = 0;
            count++; // 개수는 한 번 초기화 후에 다시 더하기
            max = level[i];
        }
        else if (level[i] == max) { // 같은 경우
            count++;
        }
    }

    cout<<num<<" "<<length<<" "<<count;
}