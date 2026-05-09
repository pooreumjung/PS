#include <string>
#include <vector>
#include <unordered_map>
#include <set>
#include <iostream>

using namespace std;

unordered_map<string,set<string>>checked; // checked는 신고당한 사람과 신고한 사람들 기록
unordered_map<string,int>result;

pair<string,string> splitReport(string s){
    pair<string,string>temp;
    int index = s.find(' ');
    temp.first = s.substr(0, index);
    temp.second = s.substr(index+1);
    return temp;
}

vector<int> solution(vector<string> id_list, vector<string> reports, int k) {
    vector<int> answer;
    
    for (int i = 0; i < reports.size(); i++) {
        pair<string, string> cur = splitReport(reports[i]);            
        checked[cur.second].insert(cur.first);                
    }
    
    // k번 이상 신고당했는지
    for (auto it = checked.begin(); it != checked.end(); it++) {
        if (it->second.size() >= k) {

            set<string> s = it->second;

            for (auto user : s) {
                result[user]++;
            }
        }
    }
    
    for(int i=0;i<id_list.size();i++)
        answer.push_back(result[id_list[i]]);
    return answer;
}

// 한 번에 한 명의 유저만 신고, 신고 횟수 제한 X, 서로 다른 유저 계속 신고, 동일한 유저에 대해서는 1번만
// k번 이상 신고된 유저는 사용 정지
// id_list => 1000, report => 200000