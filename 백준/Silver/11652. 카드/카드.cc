#include <bits/stdc++.h>
using namespace std;

map<long long,int>mp;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;

    long long num;
    pair<long long,int>p;
    p.first=LONG_LONG_MIN;
    p.second=0;

    for(int i=0;i<n;i++) {
        cin>>num;
        mp[num]++;
    }

    for (auto it=mp.begin();it!=mp.end();it++) {
        if (it->second > p.second) { 
            p.first = it->first;
            p.second = it->second;
        }
    }
    cout<<p.first;
}