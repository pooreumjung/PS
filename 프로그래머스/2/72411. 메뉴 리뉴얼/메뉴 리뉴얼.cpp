#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

set<string>mySet;
// 각 문자열들이 얼마나 주문되었는지를 저장
map<string, set<int>>mp;

// 백트래킹으로 해당 조합들 모두 탐색
void dfs(int index, string temp, string order){
    if(index > order.length())
        return;
    
    sort(temp.begin(), temp.end());
    mySet.insert(temp);
    
    for(int i=index; i<order.length();i++){
        temp.push_back(order[i]);
        dfs(i+1, temp, order);
        temp.pop_back();
    }
    
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    int index = 1;
    
    for(string order:orders){
        for(int i=0;i<order.length();i++)
            dfs(i+1, string(1, order[i]), order);
        for(auto it = mySet.begin(); it!=mySet.end(); it++){
            mp[*it].insert(index);
        }
        mySet.clear();
        index++;
    }
    
    
    for (int count : course) {
        int maxCount = 0;
        vector<string> v;

        for (auto it = mp.begin(); it != mp.end(); it++) {
            int curCount = it->second.size();

            if (it->first.length() == count && curCount >= 2) {
                if (curCount > maxCount) {
                    v.clear();
                    v.push_back(it->first);
                    maxCount = curCount;
                }
                else if (curCount == maxCount) {
                    v.push_back(it->first);
                }
            }
        }

        for (string s : v) {
            answer.push_back(s);
        }
    }
    
    sort(answer.begin(), answer.end());
    return answer;
}