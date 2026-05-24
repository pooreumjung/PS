#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<vector<int>> v;
vector<int> dist;
queue<int>q;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    v.resize(n + 1);
    dist.resize(n+1, -1);

    for(int i = 0; i < edge.size(); i++){
        int node1 = edge[i][0];
        int node2 = edge[i][1];

        v[node1].push_back(node2);
        v[node2].push_back(node1);
    }
    
    
    q.push(1);
    dist[1] = 0;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        
        vector<int>temp = v[cur];
        for(int i=0; i<temp.size();i++){
            int next = temp[i];
            if(dist[next] != -1)
                continue;
            dist[next] = dist[cur] + 1;
            q.push(next);
        }
    }
    
    sort(dist.begin(), dist.end(), greater<>());
    int max = dist[0], count=1;
    for(int i=1;i<dist.size();i++){
        if(dist[i] != max)
            break;
        count++;
    }
    return count;
}