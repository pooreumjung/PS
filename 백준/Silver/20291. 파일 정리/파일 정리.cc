#include <bits/stdc++.h>
using namespace std;

map<string, int> mp;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    string s, extension, name;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> s;

        // '.'의 위치를 찾고 substr로 분리
        size_t pos = s.find('.');
        if (pos != string::npos) {
            name = s.substr(0, pos);         // '.' 이전 부분
            extension = s.substr(pos + 1);  // '.' 이후 부분
        }

        // 확장자 카운트
        if (mp.find(extension) == mp.end()) {
            mp.insert({extension, 1});
        } else {
            mp[extension]++;
        }
    }

    // 결과 출력
    for (auto it = mp.begin(); it != mp.end(); it++) {
        cout << it->first << " " << it->second << endl;
    }
    
}
