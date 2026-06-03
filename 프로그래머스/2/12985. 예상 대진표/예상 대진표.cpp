#include <iostream>

using namespace std;

int solution(int n, int a, int b)
{
    int answer = 0;
        
    while(true){
        // a가 홀수이면서 b가 짝수이면서 같은 그룹인 경우
        if(a%2 == 1 && b%2 == 0 && b-a == 1)
            break;
        
        // b가 홀수이면서 a가 짝수이면서 같은 그룹인 경우
        if(b%2 == 1 && a%2 == 0 && a-b == 1)
            break;
            
        if(a % 2 == 0)
            a = a/2;
        else if(a%2==1)
            a = (a+1)/2;
        
        if(b%2 == 0)
            b /= 2;
        else if(b %2 ==1)
            b = (b+1)/2;
        answer++;
    }
        
    return answer+1;
}


// 1 2 3 4 5 6 7 8