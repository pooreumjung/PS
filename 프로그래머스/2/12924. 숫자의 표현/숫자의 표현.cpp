#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0, sum=0, left=1,right=1;
    
    while(true){
        
        if(left > n){            
            break;
        }
            
        if(sum == n){
            answer++;
            sum -= left;
            left++;
        }
        else if(sum < n){
            sum += right;
            right++;
        }
        else if(sum > n){
            sum -= left;
            left++;
        }
    }
    return answer;
}