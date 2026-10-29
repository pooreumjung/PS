#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;
    int left = 1, right = distance;
    
    sort(rocks.begin(), rocks.end());
    
    while(left <= right){
        int mid = left + (right-left) / 2;
        
        int removeCount = 0; // 제거한 바위 개수
        int prevPos = 0; // 이전 바위의 위치
        
        for(int rock:rocks){
            // 현재 바위와 이전 바위 사이의 거리가 mid보다 작다면
            if(rock - prevPos < mid)
                removeCount++; // mid 거리를 유지하기 위해 바위 제거
            else
                prevPos = rock;
        }
        
        // 도착지점과의 거리 체크
        if(distance - prevPos < mid)
            removeCount++;
        
        if(removeCount <= n){
            answer = mid;
            left = mid+1;
        }
        else
            right = mid-1;
    }
    
    
    return answer;
}
