#include <string>
#include <vector>

using namespace std;

int countOne(int n){
    int answer = 0;
    while(n>0){
        if(n%2==1)
            answer++;
        n/=2;
    }
    return answer;
}
int solution(int n) {
    int answer = 0, count = countOne(n);
    n++;
    while(true){
        if(countOne(n)==count){
            answer = n;
            break;
        }
        n++;
            
    }
    return answer;
}