#include <bits/stdc++.h>
using namespace std;

map<string,int>mp;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    string s1,s2;
    bool isStart = false;

    for (int i = 0; i < n; i++) {
        cin>>s1>>s2;
        if (!isStart) {
            if (s1 == "ChongChong" || s2 == "ChongChong") {
                isStart = true;
                mp[s2]++;
                mp[s1]++;
            }
        }

        else {
            if (mp.count(s1) > 0) {
                mp[s2]++;
            }
            if (mp.count(s2)>0)
                mp[s1]++;
        }
    }

    cout<<mp.size();
}