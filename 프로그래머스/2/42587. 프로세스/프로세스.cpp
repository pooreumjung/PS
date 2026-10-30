#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0, i=0;
    priority_queue<int>pq;
    queue<pair<int,int>>q;
    
    for(int prioritiy:priorities){
        pq.push(prioritiy);
        q.push(make_pair(prioritiy,i++));        
    }
    
    int count = 0;
    while(!q.empty() && !pq.empty()){
        pair<int,int>cur = q.front();
        q.pop();
        
        // 원하는 위치에 있는 프로세스를 뽑은 경우
        if(cur.first == pq.top() && cur.second == location){
            count++;
            answer = count;
            break;
        }
        
        // 그냥 가장 우선순위가 높은 프로세스만 끄낸 경우
        else if(cur.first == pq.top() && cur.second != location){
            pq.pop();            
            count++;
        }
        
        // 우선순위도 높지 않고 프로세스만 끄낸 경우
        else
            q.push(cur);                
    }
    
    return answer;
}