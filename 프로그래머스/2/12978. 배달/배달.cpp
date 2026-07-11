#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF 99999999
vector<vector<pair<int,int>>>graph;
priority_queue<pair<int,int>>pq;

vector<int> dijkstra(int start, int N){
    
    vector<int>timeArr(N+1, INF);
    timeArr[start] = 0;
    pq.push({0,start});
    
    while(!pq.empty()){
        int cur_time = pq.top().first;
        int cur_node = pq.top().second;
        pq.pop();
        
        for(int i=0; i<graph[cur_node].size();i++){
            int next_node = graph[cur_node][i].first;
            int next_time = graph[cur_node][i].second;
            
            if(timeArr[cur_node]+next_time < timeArr[next_node]){
                timeArr[next_node] = timeArr[cur_node]+next_time;
                pq.push(make_pair(next_time, next_node));
            }
        }
        
    }
    
    return timeArr;
}

int solution(int N, vector<vector<int>> road, int K) {
    
    int answer = 0;
    graph.resize(N+1);
    
    // graph 세팅
    for(int i=0; i<road.size();i++){
        int node1 = road[i][0];
        int node2 = road[i][1];
        int time = road[i][2];
        
        graph[node1].push_back(make_pair(node2, time));
        graph[node2].push_back(make_pair(node1, time));
    }
    
    vector<int>timeArr = dijkstra(1, N);
    for(int i=1;i<timeArr.size();i++){
        if(timeArr[i] <= K)
            answer++;
    }
        
    return answer;
}