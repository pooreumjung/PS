#include <string>
#include <vector>
#include <map>
#include <list>
#include <algorithm>

using namespace std;
list<string>l;
map<string, bool>mp;

// 소문자 반환 함수
string toLower(string s){
    for(char &c : s)
        c = tolower(c);
    return s;
}
int solution(int cacheSize, vector<string> cities) {
    int answer = 0, count=0;
    if(cacheSize == 0)
        return cities.size() * 5;
    
    for(int i=0;i<cities.size();i++){
        string s = toLower(cities[i]);
        
        // 캐시 교체
        if(l.size() == cacheSize){
            auto it = mp.find(s);
            // 캐시에 존재하는 경우
            if(it != mp.end()){
                auto x = find(l.begin(), l.end(), s);
                l.erase(x);
                l.push_back(s);
                answer+=1;
            }
            // 교체하는 경우, 맨 앞의 원소를 제거
            else{                
                string first = l.front();
                auto x = mp.find(first);
                mp.erase(x);
                
                l.pop_front();
                l.push_back(s);
                mp[s] = true;
                answer+=5;                
            }
        }
        else{
            auto it = mp.find(s);
            // 페이지에 존재하는 경우, 리스트 중간 삭제 후 맨뒤로
            if(it != mp.end()){
                auto x = find(l.begin(), l.end(), s);
                l.erase(x);
                l.push_back(s);
                answer+=1;
            }
            // 페이지에 존재하지 않는 경우 그냥 맨 뒤로
            else{
                l.push_back(s);
                mp[s] = true;
                answer+=5;
            }
        }
    }
    
    return answer;
}