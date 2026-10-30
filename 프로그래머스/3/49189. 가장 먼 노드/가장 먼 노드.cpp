#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<int>>graph;
queue<pair<int,int>>q;
vector<int>dist;

int solution(int n, vector<vector<int>> edges) {
    
    graph.resize(n+1);
    dist.resize(n+1, -1);
    
    for(vector<int>edge: edges){
        int node1 = edge[0];
        int node2 = edge[1];
        
        graph[node1].push_back(node2);
        graph[node2].push_back(node1);
    }
        
    dist[1] = 0;
    q.push(make_pair(1,0));
    
    while(!q.empty()){
        pair<int,int>cur = q.front();
        q.pop();
                
        for(int next: graph[cur.first]){
            if(dist[next]==-1){
                q.push(make_pair(next,cur.second+1));
                dist[next] = cur.second+1;                
            }
        }
    }
    
    int answer = count(dist.begin(), dist.end(), *max_element(dist.begin(),dist.end()));    
    return answer;
}