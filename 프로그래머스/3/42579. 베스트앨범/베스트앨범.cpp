#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>

using namespace std;

unordered_map<string, vector<pair<int,int>>> mp;
unordered_map<string, int>mpSum;

bool compare(const pair<string, int>p1, const pair<string,int>p2){
    return p1.second > p2.second;
}
bool compare2(const pair<int,int>p1, const pair<int,int>p2){
    if(p1.first != p2.first)
        return p1.first > p2.first;
    else
        return p1.second < p2.second;
}
vector<int> solution(vector<string> genres, vector<int> plays) {
    // 초기화
    vector<int> answer;
    for(int i=0;i<genres.size();i++){
        string s= genres[i];
        mp[s].push_back(make_pair(plays[i],i));
        mpSum[s]+=plays[i];
    }
            
    // 첫 번째 정렬
    vector<pair<string,int>> v(mpSum.begin(), mpSum.end());
    sort(v.begin(), v.end(), compare);
        
    for(int i=0;i<v.size();i++){
        pair<string,int> cur = v[i];
        string temp = cur.first;
        vector<pair<int,int>> v2 = mp[temp];
        sort(v2.begin(), v2.end(), compare2);
        
        for(int j=0;j<v2.size();j++){
            answer.push_back(v2[j].second);
            if(j==1)
                break;
        }                
    }
        
    return answer;
}