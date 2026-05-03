#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> wallet, vector<int> bill) {
    // 기본 설정
    sort(wallet.begin(), wallet.end());    
    int answer = 0, minWallet = wallet[0], maxWallet = wallet[1];
    int minBill = min(bill[0],bill[1]), maxBill = max(bill[0],bill[1]);        
    
    // 탐색
    while(true){
        // maxBill <= maxWallet && minBill <= minWallet이라면 중단
        if(maxBill <= maxWallet && minBill <= minWallet)
            break;
        int temp1 = maxBill, temp2=minBill;
        temp1 /= 2;
        maxBill = max(temp1, temp2);
        minBill = min(temp1, temp2);
        answer++;
    }
    return answer;
}

