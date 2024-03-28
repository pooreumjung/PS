#include<iostream>
#include<cmath>
using namespace std;

int euler(int i);
int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	long long sum1 = 0;
	for (int i = 2; i <= n; i++) {
		sum1 += euler(i);
	}
	cout << sum1;
}
int euler(int i) {

	int result = i;
	for (int p = 2; p <= sqrt(i); p++) {
		if (i % p == 0)
			result = result - result / p;
		while (i % p == 0)
			i /= p;
	}
	if (i > 1)
		result = result - result / i;
	return result;
}