#include <iostream>
using namespace std;

const long long MOD = 1000000007;

long long power(long long a, long long m) {
    if (m == 0) return 1;

    long long temp = power(a, m / 2);
    temp = temp * temp % MOD;

    if (m % 2 == 1) temp = temp * a % MOD;
    return temp;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    k = min(k, n - k);

    long long A = 1, B = 1;
    for (int i = 0; i < k; i++) {
        A = A * (n - i) % MOD;
        B = B * (i + 1) % MOD;
    }

    cout << A * power(B, MOD - 2) % MOD << '\n';
}