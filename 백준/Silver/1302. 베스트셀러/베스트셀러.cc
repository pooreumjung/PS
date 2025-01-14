#include <bits/stdc++.h>
using namespace std;

map<string, int> mp;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,max=-1;
    cin >> n;

    string s,res;
    while (n--) {
        cin >> s;
        mp[s]++;
    }

    for (auto it = mp.begin(); it!= mp.end(); it++) {
        if (it->second>max) {
            max = it->second;
            res = it->first;
        }
    }

    cout << res;
}