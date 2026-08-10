#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

long long solution(int n, vector<int> times) {
    
    sort(times.begin(), times.end());
    long long left = times[0], maxTime = times[times.size()-1];
    long long right = maxTime * n, answer = maxTime * n;
    
    while(left <= right){
        long long mid = (left+right) / 2;
        long long count = 0;
        
        for(long long time:times)
            count += mid / time;
        
        if(count >= n){
            answer = min(answer, mid);
            right = mid - 1;
        }
        
        else
            left = mid+1;        
    }
    
    return answer;
}