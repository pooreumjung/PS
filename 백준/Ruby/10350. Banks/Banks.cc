#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<long long> a(2 * n);
    long long total = 0;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i + n] = a[i];
        total += a[i];
    }

    vector<long long> prefix(2 * n + 1, 0);

    for (int i = 0; i < 2 * n; i++) {
        prefix[i + 1] = prefix[i] + a[i];
    }

    long long answer = 0;

    for (int start = 0; start < n; start++) {
        for (int len = 1; len < n; len++) {
            long long sum = prefix[start + len] - prefix[start];

            if (sum < 0) {
                long long need = -sum;
                answer += (need + total - 1) / total;
            }
        }
    }

    cout << answer << '\n';

}