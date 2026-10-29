#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0, row = triangle.size(), col = row;
    vector<vector<int>> dp(row, vector<int>(col, 0));
    
    dp[0][0] = triangle[0][0];    
    
    for(int i=1; i<row; i++){
        int count = i+1;
        for(int j=0; j<count; j++){
            if(j==0)
                dp[i][j] = triangle[i][j] + dp[i-1][j];
            else if(j == col-1)
                dp[i][j] = triangle[i][j] + dp[i-1][j-1];
            else                
                dp[i][j] = triangle[i][j] + max(dp[i-1][j], dp[i-1][j-1]);         
        }        
    }
    
    for(int j=0; j<col; j++)
        answer = max(answer, dp[row-1][j]);
    
    return answer;
}