#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0, rows = triangle.size(), columns = triangle[rows-1].size();
    vector<vector<int>>dp(rows, vector<int>(columns, 0));
    
    for(int i=0;i<triangle.size();i++){
        for(int j=0;j<triangle[i].size();j++)
            dp[i][j] = triangle[i][j];
    }
    
    for(int i=1;i<rows;i++){
        for(int j=0;j<columns;j++){            
            if(j==0 || j == columns-1)
                dp[i][j] = dp[i][j] + dp[i-1][j];
            else
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-1])+dp[i][j];
        }
    }
                
    for(int i=0;i<columns;i++)
        answer = max(answer, dp[rows-1][i]);
    
    return answer;
}