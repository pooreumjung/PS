#include <bits/stdc++.h>
using namespace std;

int uClid(int a, int b) {
    if (b == 0) return a;
    return uClid(b, a % b);
}

int lcm(int a, int b) {
    return a * b / uClid(a, b);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> v(5);
    set<int> s;

    for (int i = 0; i < 5; i++) {
        cin >> v[i];
    }

    // 서로 다른 3개의 인덱스 조합
    for (int i = 0; i < 5; i++) {
        for (int j = i + 1; j < 5; j++) {
            for (int k = j + 1; k < 5; k++) {
                int lcm1 = lcm(v[i], v[j]);
                int lcm2 = lcm(lcm1, v[k]);
                s.insert(lcm2);
            }
        }
    }

    // 출력
    cout<<*s.begin();
}
