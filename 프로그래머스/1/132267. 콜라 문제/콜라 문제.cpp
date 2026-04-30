#include <string>
#include <vector>

using namespace std;

// a가 교환을 위한 수, b가 교환받는 수, n이 전체 개수
int solution(int a, int b, int n) {
    int answer = 0;
    while(n>=a){
        int div = n/a;
        int temp = div*b;
        n -= div*a;
        n+=temp;
        answer+=temp;
    }
    return answer;
}