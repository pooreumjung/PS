#include<bits/stdc++.h>
using namespace std;

map<string, int> mp;
vector<int> parent;
vector<int> setSize;

int getParent(int node) {
    if (node == parent[node])
        return node;
    return parent[node] = getParent(parent[node]);
}

bool isSameParent(int node1, int node2) {
    return getParent(node1) == getParent(node2);
}

void Union(int node1, int node2) {
    int parent1 = getParent(node1);
    int parent2 = getParent(node2);

    if (parent1 > parent2)
        swap(parent1, parent2);

    parent[parent2] = parent1;
    setSize[parent1] += setSize[parent2];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, n;
    cin >> t;

    while (t--) {
        cin >> n;
        int index = 0;
        set<string> nameSet;
        queue<pair<string, string> > orderQueue;

        // 우선 입력값 저장
        for (int i = 0; i < n; i++) {
            string s1, s2;
            cin >> s1 >> s2;

            nameSet.insert(s1);
            nameSet.insert(s2);

            orderQueue.push(make_pair(s1, s2));
        }

        // 각 이름에 대한 인덱스 설정
        for (const string &it: nameSet) {
            mp[it] = index++;
        }

        // parent 배열 세팅
        parent.resize(nameSet.size());
        for (int i = 0; i < parent.size(); i++)
            parent[i] = i;
        setSize.resize(nameSet.size(),1);

        while (!orderQueue.empty()) {
            pair<string, string> cur = orderQueue.front();
            orderQueue.pop();

            int node1 = mp[cur.first];
            int node2 = mp[cur.second];

            if (!isSameParent(node1, node2))
                Union(node1, node2);

            if (node1 > node2)
                swap(node1, node2);

            cout<<setSize[getParent(node1)]<<'\n';
        }

        parent.clear();
        mp.clear();
        nameSet.clear();
        setSize.clear();
    }
}