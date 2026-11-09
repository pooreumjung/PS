#include <vector>
#include <iostream>
using namespace std;

vector<vector<int>>dp;
int solution(vector<vector<int>> board)
{
    int answer = 0;
    int row = board.size(), column = board[0].size();
    dp.resize(row, vector<int>(column,0));
    
    dp = board;
    
    for(int i=0;i<row; i++){
        for(int j=0; j<column; j++){
            if(i == 0 || j == 0){                
                answer = max(answer, dp[i][j]);
                continue;        
            }
            
            if(board[i][j] == 0)
                continue;
            
            dp[i][j] = min(dp[i-1][j],min(dp[i][j-1], dp[i-1][j-1]))+1;
            
            answer = max(answer, dp[i][j]);
        }
    }
        
    return answer * answer;
}

// 0 1 1 1
// 1 1 2 2
// 1 2 2 3
// 0 0 1 0