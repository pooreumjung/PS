#include <string>
#include <vector>
#include <tuple>
#include <queue>
#include <algorithm>

using namespace std;

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

int bfs(int rowSize, int columnSize, int startDir, vector<vector<int>>board){
    const int INF = 999999;
    
    queue<tuple<int,int,int>>q;
        
    vector<vector<vector<int>>> cost(
        rowSize,
        vector<vector<int>>(columnSize, vector<int>(4,INF))
    );
    
    q.push({0,0,startDir});
    cost[0][0][startDir] = 0;
    
    while(!q.empty()){
        auto [curX, curY, curDir] = q.front();
        q.pop();
        
        int curCost = cost[curX][curY][curDir];
        
        for(int nextDir = 0; nextDir<4; nextDir++){
            int nx = curX + dx[nextDir];
            int ny = curY + dy[nextDir];
            
            if(nx <0 || ny<0 || nx>=rowSize || ny>=columnSize) continue;
            
            if(board[nx][ny] == 1) continue;
            
            int nextCost = curCost + 100;
            if(curDir != nextDir)
                nextCost += 500;
            
            if(nextCost < cost[nx][ny][nextDir]){
                cost[nx][ny][nextDir] = nextCost;
                q.push({nx, ny, nextDir});
            }
        }
    }
    
    return min({
        cost[rowSize - 1][columnSize - 1][0],
        cost[rowSize - 1][columnSize - 1][1],
        cost[rowSize - 1][columnSize - 1][2],
        cost[rowSize - 1][columnSize - 1][3]
    });
}

int solution(vector<vector<int>> board) {
    int rowSize = board.size();
    int columnSize = board[0].size();
    
    // 오른쪽 또는 아래로 출발
    return min(
        bfs(rowSize, columnSize, 0, board), // 오른쪽
        bfs(rowSize, columnSize, 1, board) // 아래
    );
}