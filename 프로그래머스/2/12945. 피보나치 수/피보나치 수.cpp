#include <string>
#include <vector>

using namespace std;

int fibo[100001];
int solution(int n) {
    if(n==2)
        return 1;
    int answer = 0;
    fibo[1] = 1; fibo[2]=1;
        
    for(int i=3;i<=n;i++)
        fibo[i] = (fibo[i-1]+fibo[i-2])%1234567;
    return fibo[n];
}