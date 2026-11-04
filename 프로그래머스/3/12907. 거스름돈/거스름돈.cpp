#include <vector>

using namespace std;

const int MOD = 1000000007;

int solution(int n, vector<int> money) {
        
    vector<int>dp(n+1, 0); // dp[m]은 m원을 만드는 경우의 수
    
    // 0원을 만드는 방법은 1가지
    dp[0]=1;
    
    for(int i=0; i<money.size();i++){
        int coin = money[i];
        for(int m = coin; m<=n;m++)
            dp[m] = (dp[m]+dp[m-coin])%MOD;
    }
    
    return dp[n];
}