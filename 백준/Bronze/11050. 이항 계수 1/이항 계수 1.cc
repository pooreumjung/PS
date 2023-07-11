#include<iostream>
using namespace std;
long long fact(int n);
int main() {
	int n, k;
	cin >> n >> k;
	long long a = fact(n) / (fact(k) * fact(n - k));
	cout << a;


}

long long fact(int n) {
	if (n == 0 || n == 1)
		return 1;
	else
		return (n * fact(n - 1));
}