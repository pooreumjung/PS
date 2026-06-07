#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <cmath>

using namespace std;

map<string, pair<int,int>>parkSum;
void init(string record){
    string time = record.substr(0,5), number = record.substr(6,4), op = record.substr(11);
    string hour = time.substr(0,2), minute = time.substr(3);
    int totalTime = stoi(hour)*60 + stoi(minute);    
        
    auto it = parkSum.find(number);
    // 입차인 경우
    if(op == "IN"){        
        // 맨 처음인 경우
        if(it == parkSum.end())            
            parkSum[number] = make_pair(totalTime,0);        
        else
            it->second.first = totalTime;        
    }
    // 출차인 경우
    else{
        int lastTime = it->second.first;
        int diff = totalTime - lastTime;
        parkSum[number] = make_pair(-1, it->second.second+diff);
    }    
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int>answer;
    // 초기 세팅
    for(string record:records)
        init(record);
    
    // 빠져나간 차가 없는지 한번 더 검사
    for(auto it=parkSum.begin(); it!=parkSum.end();it++){
        if(it->second.first != -1){
            it->second.second += (1439-it->second.first);
            it->second.first = 0;
        }
                    
        int total = it->second.second;         
        if(total <= fees[0])
            answer.push_back(fees[1]);
        else{
            int diff = ceil((1.0*total-fees[0])/fees[2]);
            int sum =  fees[1] + diff*fees[3];
            answer.push_back(sum);
        }
    }
    
    return answer;
}