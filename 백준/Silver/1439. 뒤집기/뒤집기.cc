#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    int zeroCount = 0, oneCount = 0;
    if (s[0] == '0') zeroCount++;
    else oneCount++;

    for (int i = 1; i < s.length(); i++) {
        if (s[i] != s[i - 1]) {
            if (s[i] == '0') zeroCount++;
            else oneCount++;
        }
    }
    cout << min(zeroCount, oneCount);
}
