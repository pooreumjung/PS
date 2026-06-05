#include <string>
#include <vector>
#include <unordered_map>

using namespace std;
unordered_map<string,int>mp;

// 한 글자씩 탐색 => 현재 문장이 사전에 있는지 검색, 있다면 계속해서 ++, 없다면 추가 초기화 탐색
vector<int> solution(string msg) {
    
    vector<int> answer;
    int index = 27, left = 0, right = 0, temp =0;
    for (char c = 'A'; c <= 'Z'; c++) 
        mp[string(1, c)] = c - 'A' + 1;
    
    string cur = ""; char next;
    while(left < msg.length()){
        cur.push_back(msg[left]);
        
        // 현재 입력 탐색 => 사전에 등록되어 있지 않을 떄까지 CUR에 문자 붙이기
        
        while(true){
            // 사전 등록 탐색
            auto it = mp.find(cur);
            if(it == mp.end()){
                answer.push_back(temp);
                mp[cur] = index++;
                cur = "";
                break;
            }
            else
                temp = it->second;
            left++;
            if(left == msg.length())
                break;
            cur.push_back(msg[left]);                        
        }                        
    }
    answer.push_back(temp);
    
    return answer;
}

// A B C D E F G
// H I J K L M N
// O P Q R S T U
// V W X Y Z