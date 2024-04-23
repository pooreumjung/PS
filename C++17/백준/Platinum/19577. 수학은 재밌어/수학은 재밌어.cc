#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

vector<long long>v;
void findPrime(long long n);
long long eulerPhi(long long n);
int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long n;
	cin >> n;
	if (n == 1) {
		cout << 1;
		return 0;
	}
	else {
		findPrime(n);
		for (int i = 0; i < v.size(); i++) {
			if (v[i] * eulerPhi(v[i]) == n) {
				cout << v[i];
				return 0;
			}
		}
	}
	cout << -1;
}
void findPrime(long long n) {
	for (long i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) {
			v.push_back(i);
			v.push_back(n / i);
		}
	}
	v.push_back(n);
}

long long eulerPhi(long long n)
{
	long long res = n;
	for (long long i = 2; i * i <= n; i++) {
		if (n % i == 0)
			res = res / i * (i - 1);
		while (n % i == 0)
			n /= i;
	}
	if (n > 1)
		res = res / n * (n - 1);
	return res;
}
