#include <bits/stdc++.h>

#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int arr[] = {
        31, 28, 31, 30,
        31, 30, 31, 31,
        30, 31, 30, 31
};

int cal(int y, int M) {
    int r = 0;
    for (int i = 1; i <= y; ++i) {
        for (int j = 0; j < (i == y ? M - 1 : 12); ++j) {
            r += arr[j];
            if (j == 1 && ((i % 400 == 0) || (i % 4 == 0 && i % 100 != 0))) {
                ++r;
            }
        }
    }
    return r;
}

int main() {
    fastio;
    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    int ans = cal(d, e) + f - cal(a, b) - c;
    cout << (ans > cal(1001, 1) ? "gg" : "D-" + to_string(ans));
    return 0;
}