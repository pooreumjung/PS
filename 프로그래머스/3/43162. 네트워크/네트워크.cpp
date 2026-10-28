#include <string>
#include <vector>

using namespace std;

vector<vector<int>>graph;
vector<bool>visited;

// 1 1 0
// 1 1 0
// 0 0 1
void dfs(int start){
    visited[start] = true;
    vector<int>v = graph[start];
    if(v.size() == 0) return;
    
    for(int i=0; i<v.size();i++){
        int next = v[i];
        if(!visited[next])
            dfs(next);
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    graph.resize(n);
    visited.resize(n, false);
    
    for(int i=0; i<computers.size();i++){
        for(int j=0; j<computers[i].size();j++){
            if(i == j) continue;
            if(computers[i][j] == 1)
                graph[i].push_back(j);
        }
    }
    
    for(int i=0;i<n;i++){
        if(!visited[i]){
            dfs(i);
            answer++;
        }
    }
    
    return answer;
}