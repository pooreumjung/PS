#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    
    if (n == 1 || n== 2)
        return n;
    
    int a=1, b=2, c;
    
    for(int i=3;i<=n;i++){
        c = (a+b) % 1000000007;
        a = b;
        b = c;        
    }
    
    return c;
}


