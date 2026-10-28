#include <string>
#include <vector>
#include <tuple>
#include <iostream>
#include <queue>

using namespace std;

int dx[4] = {0,1,0,-1};
int dy[4] = {-1,0,1,0};

int startX, startY, endX, endY;
vector<string>board;
queue<pair<int,int>>q;
vector<vector<int>>dist;

// 시작점, 도착점 찾기
void init(){
    for(int i=0;i<board.size();i++){
        for(int j=0; j<board[i].length();j++){
            if(board[i][j] == 'R'){
                startX = i;
                startY = j;
            }
            else if(board[i][j] == 'G'){
                endX = i;
                endY = j;
            }
        }
    }
}
int solution(vector<string> board2) {
    int answer = 0, rowSize = board2.size(), columnSize = board2[0].length();
    board = board2;
    init();
    
    dist.resize(rowSize, vector<int>(columnSize,-1));
    dist[startX][startY] = 0;
    q.push(make_pair(startX, startY));
    
    while(!q.empty()){
        pair<int,int> cur = q.front();
        q.pop();
        
        for(int i=0;i<4;i++){
            int nx = cur.first;
            int ny = cur.second;
                                    
            while(true){
                int tx = nx + dx[i];
                int ty = ny + dy[i];
                
                if(tx <0 || ty<0 || tx>=rowSize || ty >=columnSize) break;                                                
                if(board[tx][ty] == 'D') break;
                
                nx = tx;
                ny = ty;
            }
            
            if(dist[nx][ny] == -1){
                dist[nx][ny] = dist[cur.first][cur.second]+1;
                q.push(make_pair(nx,ny));
            }            
        }                
    }
        
    return dist[endX][endY];
}