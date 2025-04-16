#include<bits/stdc++.h>
using namespace std;

vector<int>parent;

// 부모 노드를 구하는 함수
int getParent(int node) {
    if (node == parent[node])
        return node;
    return parent[node] = getParent(parent[node]);
}

// 부모 노드가 같은지 비교하는 함수
bool isSameParent(int node1, int node2) {
    return getParent(node1) == getParent(node2);
}

// 노드 간의 경로 설정
void Union(int node1,int node2) {
    if (node1>node2)
        swap(node1,node2);

    int parent1 = getParent(node1);
    int parent2 = getParent(node2);

    parent[parent2] = parent1;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t,count=1;
    cin>>t;

    while (t--) {
        int n,k,m;
        cin>>n>>k;

        parent.resize(n);
        for(int i=0;i<n;i++) {
            parent[i]=i;
        }

        for(int i=0;i<k;i++) {
            int node1,node2;
            cin>>node1>>node2;

            if (!isSameParent(node1,node2))
                Union(node1,node2);
        }

        cin>>m;
        cout<<"Scenario "<<count++<<":"<<'\n';
        for(int i=0;i<m;i++) {
            int node1,node2;
            cin>>node1>>node2;

            if (isSameParent(node1,node2))
                cout<<1<<'\n';
            else
                cout<<0<<'\n';
        }

        parent.clear();
        cout<<'\n';

    }
}