#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

int startX, startY;
int rows, columns;

vector<vector<bool>> visited;
vector<vector<int>> arr;

// 출발지대, 도착지대 구하기
void init(vector<string> board){
    
    visited.assign(rows, vector<bool>(columns, false));
    arr.assign(rows, vector<int>(columns, -1));
    
    for(int i=0;i<rows;i++){
        for(int j=0;j<columns;j++){
            if(board[i][j] == 'R'){
                startX = i;
                startY = j;
                break;
            }                                      
        }
    }
}

int solution(vector<string> board) {
    rows = board.size(); 
    columns = board[0].size();    
    
    init(board);
    queue<tuple<int,int,int>>q; // x, y, 이동 횟수
                
    visited[startX][startY] = true;
    arr[startX][startY] = 0;
    q.push(make_tuple(startX, startY, 0));
    
    while(!q.empty()){
        auto [curX, curY, count] = q.front();
        q.pop();
        
        if(board[curX][curY] == 'G')
            return count;
        
        for(int dir = 0; dir<4; dir++){            
            int nextX = curX;
            int nextY = curY;
            
            // 벽 또는 장애물 지점까지 이동
            while(true){
                int nx = nextX + dx[dir];
                int ny = nextY + dy[dir];
                
                // 벗어나면 멈추기
                if(nx < 0 || ny < 0 || nx >= rows || ny >= columns || board[nx][ny] == 'D')
                    break; 
                
                nextX = nx;
                nextY = ny;
            }
            
            // 이미 방문 지점
            if(visited[nextX][nextY])
                continue;
            
            visited[nextX][nextY] = true;
            arr[nextX][nextY] = count + 1;
            
            q.push(make_tuple(nextX, nextY, count+1));
        }
    }
        
   return -1;
}