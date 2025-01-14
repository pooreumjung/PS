#include <bits/stdc++.h>
using namespace std;

set<string>personSet;
vector<pair<string,string>>v;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,start=0;
    cin >> n;

    string s1,s2;

    while (n--) {
        cin>>s1>>s2;
        v.push_back({s1,s2});
    }

    for (int i=0;i<v.size();i++) {
        pair<string,string>p=v[i];
        if (p.first=="ChongChong") {
            personSet.insert(p.second);
            start = i;
            break;
        }
        if (p.second=="ChongChong") {
            personSet.insert(p.first);
            start = i;
            break;
        }
    }

    for (int i= start; i<v.size(); i++) {
        pair<string,string>p=v[i];
        if (personSet.count(p.first)>0) {
            personSet.insert(p.second);
        }

        if (personSet.count(p.second) > 0) {
            personSet.insert(p.first);
        }
    }

    cout<<personSet.size();
}