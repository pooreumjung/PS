#include<bits/stdc++.h>
using namespace std;

int findRing(string s1, string s2, int s2Index) {
    if (s1.length() > s2.length())
        return 0;

    int s1Index = 0;
    for (int i = s2Index; i < s2.length(); i++) {
        if (s1[s1Index] != s2[i])
            return 0;
        s1Index++;
        if (s1Index == s1.length())
            return 1;
    }

    s2Index = 0;
    for (int i = s1Index; i < s1.length(); i++) {
        if (s1[i] != s2[s2Index])
            return 0;
        s2Index++;
    }

    return 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s1;
    cin >> s1;

    int n, ans = 0;
    cin >> n;

    while (n--) {
        string s2;
        cin >> s2;
        bool check = false;
        for (int i = 0; i < s2.length(); i++) {
            int temp = findRing(s1, s2, i);
            if (temp == 1) {
                check = true;
                break;
            }
        }
        if (check)
            ans++;
    }

    cout << ans;
}