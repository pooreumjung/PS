#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

map<string, bool>mp;
vector<string>v;
bool isPossible = false;
int answer = 999;

// 문자열끼리 비교해서 다른 문자 개수 찾기
int func(string s1, string s2){
    int count = 0;
    for(int i=0;i<s1.length();i++){
        if(s1[i] != s2[i])
            count++;
    }    
    return count;
}
// 경우의 수 탐색
void dfs(string cur, string target, int count){
    mp[cur] = true;
    if(cur == target){
        cout<<cur<<" ";
        answer = min(answer, count);
    }
    
    for(string next : v){
        if(mp[next])
            continue;
        int temp = func(cur, next);
        if(temp == 1){             
            dfs(next, target, count+1);
        }
        
    }
     mp[cur] = false;
    
}
int solution(string begin, string target, vector<string> words) {
    v = words;
    for(int i=0; i<v.size();i++)
        mp[v[i]] = false;
    dfs(begin, target, 0);
    
    if(answer == 999)
        return 0;
    else
        return answer;
}