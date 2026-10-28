#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <iostream>
using namespace std;

map<string,int> recordList, feeList;

// 처리함수
int func(string time, string number, string op){
    int hour = stoi(time.substr(0,2));
    int minute = stoi(time.substr(3));
    int total = hour*60 + minute;
    int diff = 0;
    
    if(op == "IN")
        recordList[number] = total;
    else{
        diff = total-recordList[number];            
        recordList.erase(number);
    }
    
    return diff;
}
vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
        
    // 전처리
    for(string record:records){
        string time = record.substr(0,5);
        string number = record.substr(6,4);
        string op = record.substr(11);
        
        int diff = func(time, number, op);
        
        if(op == "OUT")
            feeList[number] += diff;
    }
    
    // 출차하지 않은 차 처리
    int total = 23*60 + 59;
    for(auto it = recordList.begin(); it!= recordList.end(); it++){
        string number = it->first;        
        feeList[number] += total-it->second;    
    }
    
    // 요금 계산 및 정답 배열 추가
    for(auto it = feeList.begin(); it != feeList.end(); it++){
        int diff = it->second; // 총 누적 주차 시간
        int finalFee = fees[1]; // 기본 요금으로 시작
                
        if (diff > fees[0])         
            finalFee += ceil((double)(diff - fees[0]) / fees[2]) * fees[3];
                        
        answer.push_back(finalFee); 
    }
    return answer;
}