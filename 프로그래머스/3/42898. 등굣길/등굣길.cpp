#include <string>
#include <vector>
#include <iostream>

using namespace std;

int dp[101][101];
int solution(int m, int n, vector<vector<int>> puddles) {
                
    dp[1][1] = 1;
    
    for(vector<int>v: puddles)
        dp[v[1]][v[0]] = -1;
                
    for(int i=1;i<=n;i++){
        for(int j=1; j<=m;j++){
            if(i==1 && j == 1)
                continue;
                            
            if(dp[i][j] == -1)
                continue;
            
            if(i==1)
                dp[i][j] = dp[i][j-1]%1000000007;
            
            else if(j == 1)
                dp[i][j] = dp[i-1][j]%1000000007;
                            
            if(dp[i-1][j] == -1 && dp[i][j-1] == -1)
                dp[i][j] = 0;
            
            else if(dp[i-1][j] == -1)
                dp[i][j] = dp[i][j-1]%1000000007;
            
            else if(dp[i][j-1] == -1)
                dp[i][j] = dp[i-1][j]%1000000007;
            
            else
                dp[i][j] = (dp[i-1][j]+dp[i][j-1])%1000000007;
        }
    }
                
    return dp[n][m];
}