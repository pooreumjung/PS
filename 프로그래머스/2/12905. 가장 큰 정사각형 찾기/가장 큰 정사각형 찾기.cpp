#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> board)
{
    int rowSize = board.size();
    int colSize = board[0].size();
    int answer = 0;
    vector<vector<int>>dp(rowSize, vector<int>(colSize,0));    
    
    for(int i=0;i<rowSize;i++){
        for(int j=0;j<colSize;j++){
            if(board[i][j] == 0)
                continue;
            if(i == 0 || j == 0)
                dp[i][j] = 1;
            else{
              dp[i][j] = min({
                    dp[i - 1][j],
                    dp[i][j - 1],
                    dp[i - 1][j - 1]
                }) + 1;
            }
            
            answer = max(answer, dp[i][j]);
        }
    }
    
    return answer*answer;
}