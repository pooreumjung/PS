#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool compare(const pair<double,int>p1, const pair<double,int>p2){
    if(p1.first != p2.first)
        return p1.first > p2.first;
    return p1.second < p2.second;
}
vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<pair<double, int>>v;
    int stage = 1;
    while(stage<= N){
        // stageCount는 현재 도전한 사람의 수, completeCount는 클리어 한 사람의 수
        int challengeCount = 0, completeCount=0;
        
        // for문을 돌면서 각 단계의 클리어 한 사람의 수 계산
        for(int i=0;i<stages.size();i++){
            if(stages[i]>=stage)
                challengeCount++;
        }
        for(int i=0;i<stages.size();i++){
            if(stages[i]>stage)
                completeCount++;
        }
        
        // 실패율 계산 및, stage 업
        double temp;
        if(challengeCount ==0)
            temp = 0;
        else
            temp = (double)(challengeCount-completeCount)/challengeCount;
        
        v.push_back(make_pair(temp,stage));
        stage++;        
    }
    
    // 정렬
    sort(v.begin(), v.end(), compare);
    
    for(pair<double,int>cur:v)
        answer.push_back(cur.second);
    return answer;
}