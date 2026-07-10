#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int dest) {
    vector<int> answer, dist(n+1, -1);    
    vector<vector<int>>graph(n+1);    
    queue<int>q;
    
    // 초기 세팅
    for(int i=0;i<roads.size();i++){
        int node1 = roads[i][0];
        int node2 = roads[i][1];
        
        graph[node1].push_back(node2);
        graph[node2].push_back(node1);
    }
    
    q.push(dest);
    dist[dest] = 0;
    
    // bfs 탐색
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        
        for(int next:graph[cur]){
            // 이미 계산한 거라면 패스
            if(dist[next] != -1)
                continue;
            
            dist[next] = dist[cur]+1;
            q.push(next);
        }        
    }
    
    for(int source:sources)
        answer.push_back(dist[source]);
    
    return answer;
}