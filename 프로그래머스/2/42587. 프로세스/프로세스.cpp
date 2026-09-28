#include <deque>
#include <algorithm>
#include <queue>
#include <deque>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
        
    deque<pair<int,int>>dq;
    for(int i=0 ;i<priorities.size(); i++)
        dq.push_back(make_pair(priorities[i],i));
    
    priority_queue<int>pq(priorities.begin(), priorities.end());
    
    while(!dq.empty()){
        pair<int,int>cur = dq.front();
        dq.pop_front();
        
        if(cur.first >= pq.top()){
            answer++;
            pq.pop();
            
            if(cur.second == location) 
                return answer;
        }
        else
            dq.push_back(cur);
    }
    
}