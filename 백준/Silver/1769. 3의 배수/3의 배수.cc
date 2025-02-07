#include<bits/stdc++.h>
using namespace std;

int func(string s) {
    int number = 0;
    for (int i = 0; i < s.length(); i++) {
        number += s[i] - '0';
    }
    return number;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    int count = 0, num = 0, length = s.length();
    while (true) {
        num = func(s);
        s = to_string(num);
        count++;
        if (num < 10)
            break;
    }

    if (length==1)
        count = 0;
    cout << count << '\n';
    if (num == 3 || num == 6 || num == 9)
        cout << "YES";
    else
        cout << "NO";
}
