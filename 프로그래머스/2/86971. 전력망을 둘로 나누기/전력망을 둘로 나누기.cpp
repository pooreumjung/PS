#include <vector>
#include <cmath>
#include <set>

using namespace std;
vector<int>parent;
set<int>s;

int find(int node){
    if(parent[node] == node)
        return node;
    else
        return parent[node] = find(parent[node]);
}

void Union(int node1, int node2){
    node1 = find(node1);
    node2 = find(node2);

    if(node1 != node2)
        parent[node2] = parent[node1];
}

int func(vector<vector<int>>wires, int index, int n){

    parent.resize(n+1);
    for(int i=0;i<=n;i++)
        parent[i] = i;

    for(int i=0;i<wires.size();i++){
        if(i == index)
            continue;
        Union(wires[i][0], wires[i][1]);
    }
    
    int count1 = 0, count2 = 0;
    int start = find(1);

    for (int node = 1; node <= n; node++) {
        if (start == find(node))
            count1++;
        else
            count2++;
    }
            
    parent.clear();
    return abs(count2-count1);
}

int solution(int n, vector<vector<int>> wires) {
    int answer = 999;
    
    for(int i=0;i<wires.size();i++){
        answer = min(answer, func(wires, i, n));
    }
    
    return answer;
}
