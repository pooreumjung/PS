#include <bits/stdc++.h>
using namespace std;

map<string, int> mp;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    string s;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> s;
        s = s.substr(s.find('.' )+1);
        mp[s]++;
    }

    for (auto it = mp.begin(); it != mp.end(); it++) {
        cout << it->first << " " << it->second << "\n";
    }
}
