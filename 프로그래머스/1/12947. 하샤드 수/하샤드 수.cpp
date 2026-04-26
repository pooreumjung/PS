#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    bool answer = true;
    int temp = 0,num=x;
    while(x>0){
        temp += x%10;
        x/=10;
    }
    
    num%temp==0? answer = true : answer=false;
    return answer;
}