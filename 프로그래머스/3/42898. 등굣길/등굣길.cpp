#include <string>
#include <vector>
#include <iostream>

#define MOD 1000000007
using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    
    vector<vector<int>>dp(n+1, vector<int>(m+1,0));
    
    for(vector<int>puddle: puddles){
        int j = puddle[0];
        int i = puddle[1];
        dp[i][j] = -1;
    }
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            
            if(dp[i][j] == -1){
                dp[i][j] = 0;
                continue;
            }
            
            else if(i == 1 && j == 1)
                dp[i][j] = 1;                         
                        
            else if(j == 1) 
                dp[i][j] = dp[i-1][j] % MOD;            
                        
            else if(i == 1)
                dp[i][j] = dp[i][j-1] % MOD;   
            
            else            
                dp[i][j] = (dp[i][j-1] + dp[i-1][j])%MOD;       
        }
    }
            
    return dp[n][m];
}