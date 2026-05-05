#include <string>
#include <vector>
#include <queue>
using namespace std;

// bfs
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

int solution(vector<vector<string>> board, int h, int w) {    
    string s = board[h][w];    
    int size = board.size(), answer=0;
    
    for(int i=0;i<4;i++){
        int nx = h+dx[i];
        int ny = w+dy[i];
        if(nx < 0 || ny < 0 || nx >= size || ny >= size)
            continue;
        if(board[nx][ny] != s)
            continue;
        answer++;
    }
        
    return answer;
}

