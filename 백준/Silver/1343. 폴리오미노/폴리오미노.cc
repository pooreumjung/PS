#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s1 = "AAAA", s2 = "BB", input, result = "";
    cin >> input;

    for (int i = 0; i < input.length(); i++) {
        if (input[i] == 'X') {
            int index = 0, len = 0;
            for (index = i; index < input.length(); index++) {
                if (input[index] == '.')
                    break;
                len++;
            }
            if (len % 2 == 1) {
                // X로 이루어진 보드판의 연속한 길이가 홀수 => 덮을 수 없다
                cout << -1;
                return 0;
            }

            i = index; // 다음 탐색점 저장

            for (int j = 0; j < len / 4; j++) // "AAAA"로 덮기
                result += s1;
            len %= 4;
            for (int j = 0; j < len / 2; j++) // "BB"로 덮기
                result += s2;
        }

        result += ".";
    }
    if (input[input.length() - 1] == '.')
        cout << result;
    else
        cout << result.substr(0, result.length() - 1);
}