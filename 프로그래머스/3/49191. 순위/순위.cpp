#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> winGraph;
vector<vector<int>> loseGraph;
vector<bool>visited;

void init(int n, vector<vector<int>>results){
    winGraph.resize(n + 1);
    loseGraph.resize(n + 1);

    for (auto result : results) {
        int winner = result[0];
        int loser = result[1];
        winGraph[winner].push_back(loser); 
        loseGraph[loser].push_back(winner); 
    }
    
}
void dfs(vector<vector<int>>& graph, int cur) {

    visited[cur] = true;

    for (int next : graph[cur]) {
        if (!visited[next]) {
            dfs(graph, next);
        }
    }
}
int solution(int n, vector<vector<int>> results) {
    init(n, results);
    int answer = 0;
    
    for(int i=1;i<=n;i++){
        int known = 0;
        
        visited.assign(n+1, false);
        dfs(winGraph,i);
        
        for(int j=1;j<=n;j++){
            if(visited[j]) known++;
        }
        visited.assign(n+1, false);
        dfs(loseGraph,i);
        
        for(int j=1;j<=n;j++){
            if(visited[j]) known++;
        }
        
        if(known-2 == n-1)
            answer++;        
    }
    
    return answer;
}