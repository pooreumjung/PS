#include <string>
#include <vector>
#include <algorithm>
#include <deque>
#include <iostream>

using namespace std;

int solution(vector<int> priorities, int location) {
    // 초기 설정
    deque<pair<int,int>>dq; // 덱에 값이랑, 인덱스를 저장
    for(int i=0;i<priorities.size();i++)
        dq.push_back(make_pair(priorities[i], i));
    
    // 내림차순 정렬
    sort(priorities.begin(), priorities.end(), greater<>());
    
    int answer = 0,index=0;
    while(!dq.empty()){        
        pair<int,int> cur = dq.front();
        // 최댓값인 경우 
        if(cur.first == priorities[index]){
            answer++;
            cout<<"몇 번 들어와"<<" ";
            // location과 일치하는 경우
            if(cur.second == location)
                return answer;
            else
                dq.pop_front();
            index++;
        }
        
        // 최댓값이 아닌 경우
        else{
            dq.push_back(dq.front());
            dq.pop_front();
        }        
    }
    
    return answer;
}