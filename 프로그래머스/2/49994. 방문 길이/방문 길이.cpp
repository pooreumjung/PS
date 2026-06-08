#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <set>

using namespace std;
map<pair<int,int>, set<string>>mp;

// 방향 설정
pair<int,int> func(char op, int x, int y){
    if(op == 'U')
        return make_pair(0+x,1+y);
    else if(op == 'D')
        return make_pair(0+x,-1+y);
    else if(op == 'R')
        return make_pair(1+x,0+y);
    else
        return make_pair(-1+x,0+y);
}
int solution(string dirs) {
    int answer = 0;
    // 출발점 설정
    pair<int,int> cur = make_pair(0,0);
    
    for(int i=0; i<dirs.length();i++){
        pair<int,int> next = func(dirs[i],cur.first, cur.second);
        int nx = next.first, ny = next.second;
        
        // 범위 검사
        if(nx <-5 || ny<-5 || nx >5 || ny>5)
            continue;
        
        string nextS = to_string(nx)+to_string(ny);
        string preS = to_string(cur.first)+to_string(cur.second);
        
        if(mp[cur].find(nextS) == mp[cur].end() && mp[next].find(preS) == mp[next].end()){
            answer++;
            mp[cur].insert(nextS);
            mp[next].insert(preS);
        }
        cur = next;
        
    }
    return answer;
}