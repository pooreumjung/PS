#include <string>
#include <queue>

using namespace std;

priority_queue<int, vector<int>, greater<int>>pq;

int solution(vector<int> scoville, int K) {
                
    int answer = 0;
    bool isPossible = false;
    for(int value : scoville)
        pq.push(value);
    
    while(pq.size()>=2 && pq.top() < K){
        int first = pq.top(); pq.pop();                
        int second = pq.top(); pq.pop();        
        int sum = first + (second*2);
        
        answer++;                                        
        pq.push(sum);        
    }
    
    if(!pq.empty() && pq.top() >=K)
        return answer;
    else
        return -1;
}