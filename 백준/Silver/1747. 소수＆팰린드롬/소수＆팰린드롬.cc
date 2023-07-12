#include <iostream>
#include <math.h>
#define MAX 8000001             
int prime[MAX] = { 1, };
using namespace std;
int reverse(int n) {
	int r = 0;

	while (n != 0) {
		r *= 10;
		r += n % 10;
		n /= 10;
	}
	return r;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	for (int i = 2; i <= sqrt(MAX); i++) {
		if (prime[i] != 0)
			continue;
		for (int j = i * i; j <= MAX; j += i) {
			prime[j] = 1;
		}
	}

	int a;
	cin >> a;
	if (a == 1) {
		cout << 2;
		return 0;
	}
	int index = 0, flag = 0;
	for (int x = a; x < MAX; x++) {
		if (flag == 1)
			break;
		if (prime[x] == 0) {
			index = x;
			if (reverse(x) == index) {
				cout << index;
				return 0;
			}
		}
	}
}

