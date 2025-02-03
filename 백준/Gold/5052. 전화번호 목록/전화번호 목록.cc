#include<bits/stdc++.h>
using namespace std;

map<string,int>mp;

int countPrefixKeys(const string& prefix) {
    auto lower = mp.lower_bound(prefix);

    // next_prefix 계산 (prefix 마지막 문자를 증가시켜 범위 제한)
    string next_prefix = prefix;
    if (!next_prefix.empty()) {
        next_prefix.back()++;  // ex) "app" -> "apq"
    }

    auto upper = mp.lower_bound(next_prefix);  // upper_bound 대신 lower_bound(next_prefix) 사용

    return distance(lower, upper);
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, n;
    bool isStop = false;
    string s;
    cin >> t;

    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> s;
            mp[s]++;
        }
        for (auto it = mp.begin(); it != mp.end(); it++) {
            int count = countPrefixKeys(it->first);
            if (count>1) {
                isStop = true;
                break;
            }
        }
        if (isStop)
            cout << "NO" << '\n';
        else
            cout << "YES" << '\n';
        mp.clear();
        isStop = false;
    }
}
