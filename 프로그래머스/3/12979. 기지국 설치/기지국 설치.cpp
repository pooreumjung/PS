#include <iostream>
#include <vector>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int start = 1, answer = 0;
    int range = 2*w + 1;
            
    for(int station:stations){
        int left = station-w, right = station + w;
        if(left <0) left = 0;
        
        if (start < left) {
            int diff = left - start; // 구간 길이: (left - 1) - start + 1
            answer += (diff + range - 1) / range; // 올림 나눗셈
        }
                        
        start = max(start, right+1);
    }
        
    if(start <= n){
        int diff = n-start+1;
        answer += (diff + range - 1) / range;
    }

    return answer;
}