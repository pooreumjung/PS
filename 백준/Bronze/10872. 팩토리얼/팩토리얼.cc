#include<iostream>
using namespace std;
long long fibo(int n);
int main() {
	int n;
	cin >> n;
	long long k=fibo(n);
	cout << k;
}
long long fibo(int n) {
	if (n == 0)
		return 1;
	if (n == 1)
		return 1;
	else
		return (n*(fibo(n-1)));
}