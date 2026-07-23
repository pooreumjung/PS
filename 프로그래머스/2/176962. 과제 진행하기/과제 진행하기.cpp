#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

struct Plan{
    string name;
    int start;
    int playtime;
};

int converTime(string time){
    int hour = stoi(time.substr(0,2));
    int minute = stoi(time.substr(3));
    
    return hour*60 + minute;
}
bool compare(const Plan a, const Plan b){
    return a.start < b.start;
}
vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;
    vector<Plan> assignments;
    
    // 초기화
    for(const auto& plan: plans){
        assignments.push_back({
            plan[0],
            converTime(plan[1]),
            stoi(plan[2])
        });
    }    
    
    // 정렬
    sort(assignments.begin(), assignments.end(), compare);
    
    // 과제 이름과 남은 시간
    stack<pair<string,int>>stopped;
    
    for(int i=0;i<assignments.size()-1;i++){
        string currentName = assignments[i].name;
        int currentStart = assignments[i].start;
        int currentPlaytime = assignments[i].playtime;
        
        int nextStart = assignments[i+1].start;
        
        // 현재 과제를 수행할 수 있는 시간
        int availableTime = nextStart - currentStart;
        
        // 현재 과제를 완료할 수 있는 겨우
        if(currentPlaytime <= availableTime){
            answer.push_back(currentName);
            
            int remainTime = availableTime - currentPlaytime;
            
            // 남는 시간 동안 과제 진행
            while(remainTime >0 && !stopped.empty()){
                string stoppedName = stopped.top().first;
                int stoppedTime = stopped.top().second;
                stopped.pop();
                
                if(stoppedTime <= remainTime){
                    remainTime -= stoppedTime;
                    answer.push_back(stoppedName);
                }
                
                else{
                    stopped.push({stoppedName, stoppedTime - remainTime});
                    remainTime = 0;
                }
            }
        }
        else{
            // 현재 과제 완료못했으므로 스택에 저장
            stopped.push({currentName, currentPlaytime -availableTime });
        }
    }
    
    // 마지막 과제는 이후에 새 과제가 없으므로 무조건 완료
    answer.push_back(assignments.back().name);

    // 중단된 과제를 최근에 중단한 순서부터 완료
    while (!stopped.empty()) {
        answer.push_back(stopped.top().first);
        stopped.pop();

    }

    return answer;
}
