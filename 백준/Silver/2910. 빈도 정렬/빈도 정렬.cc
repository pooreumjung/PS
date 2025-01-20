#include <bits/stdc++.h>
using namespace std;

map<int,int>mp;
map<int,int>mp2;
vector<pair<int,int>>v;
bool compare(const pair<int,int>&p1,const pair<int,int>&p2) {
    if (p1.second==p2.second) // 빈도수가 같다면
        return p1.first < p2.first; // 먼저 나온 값을 기준으로
    return p1.second > p2.second; // 빈도수 기준 내림차순
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int  n,c,num;
    cin>>n>>c;
    v.resize(n+1);

    for(int i=0;i<n;i++) {
        cin>>num;
        auto it=mp.find(num);
        if(it==mp.end()) { //기존에 나온 수가 아닐 경우
            mp.insert({num,i+1}); // 맵에 저장(값과 나온 순서를 저장)
            mp2.insert({i+1,num});
            v[i+1].second=1; // 나온 횟수
            v[i+1].first=i+1; // 위치
        }
        else { // 기존에 나온 수라면
            v[it->second].second++;
        }
    }



    sort(v.begin(),v.end(),compare);
    for(int i=0;i<v.size();i++) {
        if (v[i].first == 0)
            break;
        int count = v[i].second;
        int num = mp2.find(v[i].first)->second;
        while (count--)
            cout<<num<<" ";
    }
}