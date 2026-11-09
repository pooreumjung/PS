#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(int N, int number) {
    
    vector<set<int>> dp(9); // dp[i]는 N을 정확히 i번 사용해 만들 수 있는 숫자들의 집합
    int repeated = 0;
    
    for(int i=1; i<=8; i++){
        // 1. N을 i번 이어 붙인 숫자
        repeated = repeated * 10 + N;
        dp[i].insert(repeated);
        
        // 2. N의 사용 횟수를 두 그룹으로 분할
        for(int j=1; j<i; j++){
            for(int a: dp[j]){
                for(int b: dp[i-j]){
                    dp[i].insert(a+b);
                    dp[i].insert(a-b);
                    dp[i].insert(a*b);
                    
                    if(b!=0)
                        dp[i].insert(a/b);
                }
            }
        }
        
        if(dp[i].count(number))
            return i;
    }
    
    return -1;
}