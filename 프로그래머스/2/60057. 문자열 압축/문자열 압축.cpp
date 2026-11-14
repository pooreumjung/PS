#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int n = s.length();
    int answer = n;
    
    for(int step = 1; step<= n/2; step++){
        string compressed = "";
        string prev = s.substr(0, step);
        int count = 1;
        
        for(int j=step; j<n; j+=step){
            string cur = s.substr(j, step);
            if(prev == cur)
                count++;
            else{
                if(count > 1) compressed += to_string(count);
                compressed += prev;
                
                prev = cur;
                count = 1;
            }
        }
        
        if(count > 1) compressed += to_string(count);
        compressed += prev;
        
        answer = min(answer, (int(compressed.length())));
    }
    
    return answer;
}