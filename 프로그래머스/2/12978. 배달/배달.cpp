#include <iostream>
#include <vector>
#include <queue>

using namespace std;
#define INF 999999999

vector<vector<pair<int,int>>>graph;
vector<int>dist;

void dij(int start){
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        
    dist[start] = 0;
    pq.push({0, start}); // 비용, 노드번호
    
    while(!pq.empty()){
        
        int curDist = pq.top().first;
        int curNode = pq.top().second;
        pq.pop();
        
        // 이미 처리된 경우는 pass
        if(dist[curNode] < curDist) continue;
        
        for(pair<int,int>cur: graph[curNode]){
            
            int nextNode = cur.first;
            int nextDist = cur.second;
            
            if(dist[nextNode] > dist[curNode] + nextDist){
                dist[nextNode] = dist[curNode] + nextDist;
                pq.push(make_pair(dist[nextNode], nextNode));
            }
        }                
    }
}

int solution(int N, vector<vector<int>> roads, int K) {
        
    int answer = 0;
    graph.resize(N+1);
    dist.resize(N+1, INF);
    
    for(vector<int>road:roads){
        int node1 = road[0];
        int node2 = road[1];
        int cost = road[2];
        
        graph[node1].push_back(make_pair(node2,cost));
        graph[node2].push_back(make_pair(node1,cost));
    }
        
    dij(1);
    for(int i = 1; i<=N; i++){        
        if(dist[i] <= K) answer++;            
    }
    
    return answer;
}