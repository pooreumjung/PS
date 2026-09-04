#include <iostream>
#include <vector>
using namespace std;

int solution(vector<int> sticker)
{
    int n = sticker.size();
    
    // 스티커가 1개인 경우
    if(n==1) return sticker[0];
    
    vector<int>dp1(n,0);
    vector<int>dp2(n,0);
    
    // 첫 번째 스티커를 뜯는 경우, 마지막 스티커는 못 뜯음
    dp1[0] = dp1[1] = sticker[0];    
    
    for(int i=2;i<n;i++)
        dp1[i] = max(dp1[i-1], dp1[i-2] + sticker[i]);
    
    dp2[0] = 0;
    dp2[1] = sticker[1];
    
    for(int i=2;i<n;i++)
        dp2[i] = max(dp2[i-1], dp2[i-2] + sticker[i]);
    
    return max(dp1[n-2], dp2[n-1]);
    
}