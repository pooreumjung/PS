#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s1, s2;
    cin >> s1 >> s2;
    
    vector<char> result;
    int s2_len = s2.length();

    for (char c : s1) {
        result.push_back(c);

        // 폭발 문자열을 발견하면 제거
        if (result.size() >= s2_len && 
            string(result.end() - s2_len, result.end()) == s2) {
            result.erase(result.end() - s2_len, result.end());
        }
    }

    if (result.empty()) cout << "FRULA";
    else cout << string(result.begin(), result.end());

    return 0;
}
