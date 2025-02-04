#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;

    for (char &c : s) {
        c = toupper(c); // 각 문자 대문자로 변환
    }

    cout << s << '\n';

    return 0;
}
