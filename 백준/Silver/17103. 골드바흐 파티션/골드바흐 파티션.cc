#include <iostream>
#include <math.h>
#define MAX 1000001             
int prime[MAX] = { 1, };
using namespace std;

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

	int n;
	cin >> n;
	int index;
	for (int x = 0; x < n; x++) {
		index = 0;
		int k;
		cin >> k;
		if (n == 0)
			break;
		bool find = false;
		for (int i = 2; i < k; i++) {
			if (i<=k-i&&prime[i] == 0 && prime[k - i] == 0) {
				index++;
				find = true;
			
			}
		}
		cout << index << '\n';

	}
}

