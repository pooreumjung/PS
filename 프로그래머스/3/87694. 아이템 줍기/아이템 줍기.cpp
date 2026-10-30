#include <queue>
#include <vector>
#include <tuple>

using namespace std;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

// 좌표를 2배 확대
int board[102][102];
bool visited[102][102];

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    
    // 1. 모든 입력 좌표를 2배로 확대
    characterX *= 2;
    characterY *= 2;
    itemX *= 2;
    itemY *= 2;
    
    // 2. 사각형 전체 영역을 1로 채우기
    for(const auto& rect: rectangle){
        int x1 = rect[0]*2, y1 = rect[1]*2;
        int x2 = rect[2]*2, y2 = rect[3]*2;
        
        for(int i = x1; i <= x2; i++){
            for(int j = y1; j <= y2; j++)
                board[i][j]=1;
        }
    }
    
    // 3. 사각형의 내부 영역을 0으로 만들기
     for(const auto& rect: rectangle){
        int x1 = rect[0]*2, y1 = rect[1]*2;
        int x2 = rect[2]*2, y2 = rect[3]*2;
        
        for(int i = x1+1; i < x2; i++){
            for(int j = y1+1; j < y2; j++)
                board[i][j]=0;
        }
    }
    
    // BFS
    queue<tuple<int,int,int>>q; // 현재x, 현재y, 이동거리
    q.push(make_tuple(characterX,characterY,0));
    visited[characterX][characterY] = true;
    
    while(!q.empty()){
        tuple<int,int,int>cur = q.front();
        q.pop();
        
        int curX = get<0>(cur);
        int curY = get<1>(cur);
        int dist = get<2>(cur);
        
        if(curX == itemX && curY == itemY) return dist/2;
        
        for(int i=0; i<4; i++){
            int nx = curX+dx[i];
            int ny = curY+dy[i];
            
            if(nx>=0 && ny>=0 && nx<=100 && ny <=100){
                if(!visited[nx][ny] && board[nx][ny]==1){
                    visited[nx][ny] = true;
                    q.push(make_tuple(nx,ny,dist+1));
                }
            }
        }
    }
    return 0;
}