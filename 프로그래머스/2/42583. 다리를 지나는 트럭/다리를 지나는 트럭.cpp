#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;
// 다리를 지난 트럭, 다리를 건너는 트럭, 대기 트럭
queue<int>waitQ, workQ, finishQ;
bool visited[10001];
int solution(int bridge_length, int weight, vector<int> truck_weights) {
    // 초기 세팅
    for(int i=0;i<truck_weights.size();i++)
        waitQ.push(truck_weights[i]);    
    int answer = 1, curWeight=0, lastIndex=0, startIndex=0;
    vector<int>temp;
    
    while(true){
        // 모두 다 건넜으면 반복문 종료
        if(finishQ.size() == truck_weights.size())
            break;
        
        // 다리가 버틸 수 있는 최대 무게만큼 트럭 건너게 하기
        if(!waitQ.empty()){
            int truck = waitQ.front();            
            if(curWeight + truck <= weight && workQ.size() < bridge_length ){
                // 다리 건너게 만들기
                workQ.push(truck);
                waitQ.pop();
                
                temp.push_back(bridge_length);                
                curWeight += truck;    
                cout<<answer<<"초: "<<truck<<'\n';
            }
        }
        
        answer++;
        for(int i=0;i<temp.size();i++){
            temp[i] -= 1;
            if(temp[i] <0)
                temp[i] = 0;
            // 다 건넌 경우, workQ -> finishQ로 이동
            if(temp[i] == 0 && !visited[i]){
                int truck = workQ.front();
                workQ.pop();                
                finishQ.push(truck);                
                
                curWeight -= truck;                
                visited[i] = true;                       
            }
        }
        
    }
    
    return answer;
}