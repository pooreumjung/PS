#include <iostream>
#include <vector>

using namespace std;

int dp[100001][4];
int solution(vector<vector<int>>land)
{
    int answer = 0, row = land.size(), col = 4;
    for(int j=0; j<col; j++)
        dp[0][j] = land[0][j];

    for(int i=1; i<row; i++){
        dp[i][0] = land[i][0] + max(dp[i-1][3], max(dp[i-1][1],dp[i-1][2]));
        dp[i][1] = land[i][1] + max(dp[i-1][3], max(dp[i-1][0],dp[i-1][2]));
        dp[i][2] = land[i][2] + max(dp[i-1][3], max(dp[i-1][1],dp[i-1][0]));
        dp[i][3] = land[i][3] + max(dp[i-1][0], max(dp[i-1][1],dp[i-1][2]));                
    }
            
    for(int i=0;i<col;i++)        
        answer = max(answer, dp[row-1][i]);

    return answer;
}