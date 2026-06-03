#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;
vector<vector<string>>v;
map<string,bool>mp;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    vector<string>temp;
    
    // 초기 세팅
    for(int i=0; i<words.size();i++){
        temp.push_back(words[i]);    
        
        if((i+1)%n == 0){
            v.push_back(temp);
            temp.clear();
        }                
    }
    
    // 탐색
    bool isEnd = false;   
    int count = 0;
    for(int i=0;i<v.size();i++){
        for(int j=0;j<v[i].size();j++){
            string s = v[i][j];
            
            if(count >=1){
                if(words[count-1].back() != s.front()){
                    answer.push_back(j+1);
                    answer.push_back(i+1);                    
                    isEnd = true;
                    break;
                }
            }
                        
            // 중복해서 말하는 경우
            auto it = mp.find(s);            
            if(it != mp.end()){
                answer.push_back(j+1);
                answer.push_back(i+1);                
                isEnd = true;
                break;
            }
            mp[s] = true;
            count++;
        }        
        if(isEnd)
            break;
    }
    
    if(!isEnd){
        answer.push_back(0);
        answer.push_back(0);
    }

    return answer;
}