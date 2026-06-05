#include <string>
#include <vector>
#include <map>
#include <set>
#include <iostream>

using namespace std;
vector<string> answer;

// 유저 닉네임 인덱스 검사용
map<string, vector<int>>mp;
map<string, string>idMap;

int index = 0;

// 유저 아이디는 중복 불가, 닉네임은 중복 가능
void func(vector<string>records){
    string op = records[0];
    
    // 들어온 경우
    if(op == "Enter"){
        // id랑 nickname 가져오기
        string id = records[1], nickname = records[2];        
        
        auto it = idMap.find(id);        
        // 동일한 아이디로 닉네임을 바꿔서 들어온 경우
        if(it != idMap.end() && it->second != nickname){                        
            vector<int>v = mp.find(id)->second;
            for(int i=0;i<v.size();i++){
                // 기존 문장 교체
                string temp = answer[v[i]];            
                temp = temp.replace(0, it->second.length(), nickname); 

                answer[v[i]] = temp;                                
            }            
        }
        // map 세팅
        idMap[id] = nickname;
        mp[id].push_back(index++);
        
        // answer에 추가
        string s = nickname+"님이 들어왔습니다.";        
        answer.push_back(s);
    }
    
    // 나가는 경우
    else if(op == "Leave"){
        
        string id = records[1];
        auto it = idMap.find(id);
        string nickname = it->second;
                
        string s = nickname+"님이 나갔습니다.";
        answer.push_back(s);        
        mp[id].push_back(index++);        
    }
    
    // 이름을 바꾸는 경우
    else{
        
        // id랑 바꿀 nickname 가져오기
        string id = records[1], changeNickname = records[2];
        
        // 인덱스 리스트랑 원래 이름 가져오기        
        vector<int> v = mp.find(id) -> second;        
        auto it = idMap.find(id);
        string originalNickname = it->second;        
        
        // answer에 인덱스에 해당하는 값들 변경
        for(int i=0;i<v.size();i++){
            // 기존 문장 교체
            string temp = answer[v[i]];            
            temp = temp.replace(0, originalNickname.length(), changeNickname); 
                        
            answer[v[i]] = temp;            
            it->second = changeNickname;
        }
    }
    
}
vector<string> solution(vector<string> records) {
                
    for(string record: records){
        int start = 0, end = 0;
        vector<string> v;
        string temp ="";
        while((end = record.find(' ',start)) != string::npos){
            temp = record.substr(start, end-start);
            v.push_back(temp);
            start = end+1;
        }
        v.push_back(record.substr(start));        
        func(v);
    }
    
    return answer;   
}