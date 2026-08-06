#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> stations, int w) {
    int answer = 0, start = 1, range = 2 * w + 1;
    
    for(int station: stations){
        int left = station - w; // 전파 시작점
        int length = left - start; // 커버해야 하는 구간
        
        if(length>0) answer += (length+range-1) / range;
        start = station + w + 1;
    }
    
    // 마지막 기지국 이후의 빈 구간
    if (start <= n) {
        int length = n - start + 1;
        answer += (length + range - 1) / range;
    }
        

    return answer;
}