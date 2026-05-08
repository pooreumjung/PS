#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>

using namespace std;

unordered_map<char,int>mp;
// terms 세팅
void init(vector<string>terms){
    for(int i=0;i<terms.size();i++){
        string s = terms[i];
        mp[s[0]] = stoi(s.substr(2));
    }
}

// 전체 일수 구해주기
pair<int,int> func(string privacie){
    // 연/월/일 구하기
    int year = stoi(privacie.substr(0,4));
    int month = stoi(privacie.substr(5,2));
    int day = stoi(privacie.substr(8,2));
    int allDay = (month-1)*28 + day;
    return make_pair(year, allDay);
}
vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    init(terms);
    
    for(int i=0;i<privacies.size();i++){
        string privacie = privacies[i];        
        char c = privacie.back();
        pair<int,int>cur = func(privacie);                
        
        int allDay = mp[c]*28 + cur.second-1;                
        int year = cur.first + allDay/336;
        int month = (allDay%336)/28+1;
        int day = allDay%28;
        
        if(day == 0){
            month -= 1;
            day = 28;
        }
        
        string s = to_string(year) + ".";
        if(month < 10)
            s += "0";
        s += to_string(month) + ".";

        if(day < 10)
            s += "0";
        s += to_string(day);
        
        if(today > s)
            answer.push_back(i+1);
    }
    sort(answer.begin(), answer.end());
    return answer;
}

// 파기해야 할 개인정보의 번호를 오름차순으로 반환
// 모든 달은 28일로 가정
// 유효기간은 1이상 100이하로 달을 의미함
// today는 항상 10글자
// terms는 약관 종류와 유효기간
// 유효기간을 셀때는 오늘날짜를 포함함