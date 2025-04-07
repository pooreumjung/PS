#include<bits/stdc++.h>
using namespace std;

int bfs2Hop(int start, const vector<vector<int>>& adj, int n) {
    vector<bool> visited(n, false);
    queue<pair<int, int>> q;
    unordered_set<int> result;

    visited[start] = true;
    q.push({start, 0});

    while (!q.empty()) {
        auto [cur, depth] = q.front(); q.pop();

        if (depth == 2) continue;

        for (int next : adj[cur]) {
            if (!visited[next]) {
                visited[next] = true;
                result.insert(next);
                q.push({next, depth + 1});
            }
        }
    }

    return result.size();
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, e;
        cin >> n >> e;

        unordered_map<string, int> nameToIndex;
        vector<string> indexToName(n);
        int idx = 0;

        vector<vector<int>> adj(n);

        for (int i = 0; i < e; ++i) {
            string uName, vName;
            cin >> uName >> vName;

            if (nameToIndex.find(uName) == nameToIndex.end()) {
                nameToIndex[uName] = idx;
                indexToName[idx++] = uName;
            }
            if (nameToIndex.find(vName) == nameToIndex.end()) {
                nameToIndex[vName] = idx;
                indexToName[idx++] = vName;
            }

            int u = nameToIndex[uName];
            int v = nameToIndex[vName];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        string startName;
        cin >> startName;
        int start = nameToIndex[startName];

        int count = bfs2Hop(start, adj, n);
        cout<<"The number of supervillains in 2-hop neighborhood of "<<startName<<" is "<<count<<'\n';
    }

}