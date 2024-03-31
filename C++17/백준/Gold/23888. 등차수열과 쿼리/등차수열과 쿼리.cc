#include<iostream>
#include<vector>

using namespace std;
long long gcd(long long a, long long b);
int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long a, d, q;
	cin >> a >> d >> q;

	for (int i = 0; i < q; i++) {
		long long k, l, r;
		cin >> k >> l >> r;
		if (k == 1) {
			if (l == r) {
				cout << a + (l - 1) * d << '\n';
			}
			else {
				long long sum1 = a + (l - 1) * d;
				long long sum2 = a + (r - 1) * d;
				long long sum3 = sum1 + sum2;
				long long sum4 = sum3 * (r - l + 1);
				cout << sum4 / 2 << "\n";
			}
		}
		else if (k == 2) {
			if (l == r)
				cout << a + (l - 1) * d << '\n';
			else
				cout << gcd(a, d) << '\n';
		}
	}
}
long long gcd(long long a, long long b) {
	if (b == 0)
		return a;
	else
		return gcd(b, a % b);
}
