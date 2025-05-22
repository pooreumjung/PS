#include<iostream>
using namespace std;

int cnt1 = 0, cnt2 = 0;
int fib(int n);
int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	fib(n);

	cout << cnt1+1 << " " << n-2;
}
int fib(int n) {
	if (n == 1 || n == 2) {
		return 1;
	}

	else {
		cnt1++;
		return (fib(n - 1) + fib(n - 2));
	}
}