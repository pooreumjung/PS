#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>>graph;
vector<int>dist;

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int dest) {
    
    graph.resize(n+1);
    dist.resize(n+1, -1);
    
    // 그래프 초기 세팅
    for(vector<int>road: roads){
        int node1 = road[0];
        int node2 = road[1];
        
        graph[node1].push_back(node2);
        graph[node2].push_back(node1);
    }
    
    queue<int>q;
    q.push(dest);
    dist[dest] = 0;
         
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        
        for(int next: graph[cur]){
            if(dist[next] == -1){
                dist[next] = dist[cur] + 1;
                q.push(next);
            }
        }
    }
        
    vector<int>answer;
    for(int source: sources)
        answer.push_back(dist[source]);
    
    return answer;
    
}