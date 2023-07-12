#include <iostream>
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    long long answer = 0;
    int start = 1, end = 10;
    int len = 1;
    while(1){
        for(int i=start; i < end; ++i){
            if(i > N){
                cout << answer << '\n';
                return 0;
            }
            
            answer += len;
        }
       
        start *= 10; end *= 10;
        len++;
    }
}