#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    int result = 0;
    for (int i = 0; i < 8; i++) {
        cin >> s;
        if (i % 2 == 0) {
            for (int j = 0; j < s.length(); j += 2) {
                if (s[j] == 'F')
                    result++;
            }
        } else {
            for (int j = 1; j < s.length(); j += 2) {
                if (s[j] == 'F')
                    result++;
            }
        }
    }
    cout << result;
}