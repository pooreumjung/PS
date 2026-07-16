#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

// mp1은 string이 받은 사람, mp2는 string이 준 사람
map<string, multiset<string>>mp1, mp2;
// countMp1은 string이 받은 선물, countMp2는 string이 준 선물, result는 받을 선물
map<string, int> countMp1, countMp2, giftMp, result;

void func(vector<string>friends){
        
    for(int i=0; i<friends.size();i++){
        for(int j=i+1;j<friends.size();j++){
            string person1 = friends[i], person2 = friends[j];
            
            // count1이 person1이 받은 개수, count2는 person2가 받은 개수
            int count1 = mp1[person1].count(person2);
            int count2 = mp1[person2].count(person1);
            
            
            // person2가 더 많이 줬다면 => person2가 받아야 함
            if(count1 > count2)
                result[person2]++;                    

            // person1이 더 많이 준 경우 => person1이 받아야 함
            else if(count1 < count2)
                result[person1]++;                    

            // 주고받은 기록이 같다면
            else{
                // 선물지수가 큰 person1이 받고
               if(giftMp[person1] > giftMp[person2])
                    result[person1]++;                        

                // 선물지수가 큰 person2가 받고
                else if(giftMp[person1] < giftMp[person2])
                    result[person2]++;                                            
            }                
                                  
        }
    }   
}

// 초기화 함수
void init(vector<string>friends, vector<string>gifts){
    
    // 초기 세팅
    for(string person:friends)
        countMp1[person] = countMp2[person] = 0;
    
    for(string s:gifts){
        // 문자열 파싱
        size_t index = s.find(' ');
        string send = s.substr(0,index);
        string rec = s.substr(index+1);
        
        // 주고 받은 이력 추가
        mp1[rec].insert(send);
        mp2[send].insert(rec);
        
        // 주고 받은 선물 수 체크
        countMp1[rec]++;
        countMp2[send]++;
    }
}

int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    init(friends, gifts);
                                        
    // 각 사람의 선물 지수
    for(string person:friends)
        giftMp[person] = countMp2[person] - countMp1[person];
    
    // 선물 주고받기
    for(string person:friends)
        result[person] = 0;    
    func(friends);
    
    // 제일 큰 값 찾기
    for(string person:friends)
        answer = max(answer, result[person]);
              
    return answer;
}