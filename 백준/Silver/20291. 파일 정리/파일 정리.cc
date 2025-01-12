#include <bits/stdc++.h>
using namespace std;

map<string,int>mp;
int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    int n;
    string s,extension,name;
    cin>>n;

    for(int i=0;i<n;i++) {
        cin>>s;

        stringstream ss(s);
        getline(ss, name,'.');
        getline(ss, extension, '.');
        if(mp.find(extension) == mp.end()) {
            mp.insert({extension,1});
        }
        else {
            mp[extension]++;
        }
    }

    for (auto it=mp.begin();it!=mp.end();it++) {
        cout<<it->first<<" "<<it->second<<endl;
    }
}