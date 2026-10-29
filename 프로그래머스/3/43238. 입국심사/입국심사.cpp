#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
        
    long long max_time = *max_element(times.begin(), times.end());
    long long right = max_time * n, left = 1;
    long long answer = right;
    
    while(left <= right){
        long long mid = left + (right-left)/2;
        long long total = 0; // 심사 시간 동안 심사 받는 사람의 수
        
        for(int time:times)
            total += mid/time;
        
        if(total >= n){
            answer = mid;
            right = mid-1;
        }
        else
            left = mid+1;            
    }
    
    return answer;
}