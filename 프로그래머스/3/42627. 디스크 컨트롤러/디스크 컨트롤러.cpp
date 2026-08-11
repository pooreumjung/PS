#include <string>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>

using namespace std;

priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>,greater<tuple<int,int,int>>> pq;
int solution(vector<vector<int>> jobs) {    
    sort(jobs.begin(), jobs.end());
        
    int currentTime = 0, answer = 0, completed = 0, idx=0;
                        
    while(completed < jobs.size()){
        // 현재 시간까지 요청된 작업들을 대기 큐에 삽입
        while(idx < jobs.size() && jobs[idx][0] <= currentTime){
            int requestTime = jobs[idx][0];
            int duration = jobs[idx][1];
            pq.push({duration, requestTime, idx});
            idx++;
        }
        
        if(!pq.empty()){
            auto [duration, requestTime, jobId] = pq.top();
            pq.pop();
            
            currentTime += duration;
            answer += currentTime - requestTime;
            completed++;
        }
        
        else
            currentTime = jobs[idx][0];
    }
            
    return answer/jobs.size();
}