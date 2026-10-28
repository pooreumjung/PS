#include <vector>
#include <queue>

using namespace std;

vector<vector<int>>dist;
vector<vector<bool>>visited;
queue<pair<int,int>>q;

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

int solution(vector<vector<int> > maps)
{
    int answer = 0, rowSize = maps.size(), columnSize = maps[0].size();
    
    dist.resize(rowSize, vector<int>(columnSize,-1));
    visited.resize(rowSize, vector<bool>(columnSize,false));
    
    dist[0][0] = 1;
    visited[0][0] = true;
    q.push(make_pair(0,0));
    
    while(!q.empty()){
        pair<int,int>cur = q.front();
        q.pop();
        
        for(int i=0;i<4;i++){
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            
            if(nx<0 || ny<0 || nx>=rowSize || ny>=columnSize)
                continue;
            if(visited[nx][ny] || maps[nx][ny] == 0)
                continue;
            
            dist[nx][ny] = dist[cur.first][cur.second]+1;
            visited[nx][ny] = true;
            q.push(make_pair(nx,ny));
        }
    }
    
    return dist[rowSize-1][columnSize-1];
}