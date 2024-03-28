#include<iostream>
#include<cmath>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	while (true) {
		long long n;
		cin >> n;
		if (n == 0)
			break;
		if (n == 1) {
			cout << 0 << "\n";
			continue;
		}
		long long result = n;
		for (long long  i = 2; i *i<=n; i++) {
			if (n % i == 0)
				result = result / i * (i - 1);
			while (n % i == 0)
				n /= i;
		}
		if (n > 1)
			result = result / n * (n - 1);
		cout << result << "\n";
	}
}