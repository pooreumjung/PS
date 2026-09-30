#include <vector>
#include <queue>
using namespace std;

vector<vector<bool>>visited;
vector<vector<int>> arr;
queue<pair<int,int>>q;

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

int solution(vector<vector<int> > maps)
{
    int answer = 0, rowSize = maps.size(), columnSize = maps[0].size();
    visited.resize(rowSize, vector<bool>(columnSize, false));
    arr.resize(rowSize, vector<int>(columnSize, 999999));
    
    visited[0][0] = true;
    arr[0][0] = 0;
    q.push(make_pair(0,0));
    
    while(!q.empty()){
        pair<int,int>cur = q.front();
        q.pop();
        
        for(int i=0;i<4;i++){
            int nx = cur.first+dx[i];
            int ny = cur.second+dy[i];
            
            if(nx >= rowSize || nx < 0 || ny >=columnSize || ny < 0)
                continue;
            if(visited[nx][ny] || maps[nx][ny] == 0)
                continue;
            
            arr[nx][ny] = arr[cur.first][cur.second]+1;
            visited[nx][ny] = true;
            q.push(make_pair(nx,ny));
        }
    }
    
    if(arr[rowSize-1][columnSize-1] == 999999)
        return -1;
    else
        return arr[rowSize-1][columnSize-1]+1;    
}