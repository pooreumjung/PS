#include <map>
#include <cmath>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

map<string, int>mp, sumList;
vector<int>result;
vector<pair<string,int>>v2;

// 입출차 처리 함수
void func(vector<string>v){
    string time = v[0], number = v[1], state = v[2];
    int hour = stoi(time.substr(0,2)), minute = stoi(time.substr(3));
    int total = hour*60 + minute;
        
    auto it = mp.find(number);
        
    // 출차인 경우
    if(it != mp.end()){
        int diff = total - it->second;        
        sumList[number] += diff;
        
        mp.erase(it);
    }
    // 입차인 경우
    else
        mp[number] = total;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    for(string record:records){
        vector<string>v;
        size_t pos = 0, start = 0; 
        while((pos = record.find(' ', start)) != string::npos){
            string temp = record.substr(start, pos-start);
            v.push_back(temp);
            
            start = pos+1;
        }
        v.push_back(record.substr(start));
        
        func(v);
    }    
    
    // 예외 검사
    for(auto it = mp.begin(); it!=mp.end();it++){
        int diff = 1439 - it->second;                
        sumList[it->first] += diff;
    }
    
    for(auto it=sumList.begin(); it!=sumList.end(); it++){
        
        int diff = it->second - fees[0];
        if(diff <=0)
            diff = 0;
        
        int sum = fees[1] + (int)(ceil((double)diff / fees[2])) * fees[3];
        result.push_back(sum);
    }
    
    return result;
}