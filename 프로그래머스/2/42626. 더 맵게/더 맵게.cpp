#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scovilles, int K) {
    int answer = 0;
        
    priority_queue<int, vector<int>, greater<int>>pq;
    for(int scoville: scovilles) pq.push(scoville);
    
    while(!pq.empty()){
        int scoville1 = pq.top();
        pq.pop();
        
        if(scoville1 >= K)break;        
        if(pq.size() == 0) return -1;
        
        int scoville2 = pq.top();
        pq.pop();
        
        int total = scoville1 + 2*scoville2;
                
        pq.push(total);
        answer++;
    }
    
    return answer;
}