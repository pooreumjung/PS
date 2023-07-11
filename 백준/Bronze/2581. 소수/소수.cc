#include<iostream>
using namespace std;
int find(int n);
int main() {
	int m, n;
	cin >> m >> n;
	int min = 10001;
	int cnt = 0,sum=0;
	for (int x = m; x <= n; x++) {
		int res = find(x);
		if (res == 1) {
			cnt++;
			sum += x;
			if (min > x)
				min = x;
		}
	}
	if (cnt == 0)
		cout << -1;
	else
	cout << sum << "\n" << min;
}
int find(int n) {
	int cnt = 0;
	if (n == 1)
		return 0;
	if (n == 2)
		return 1;
	else {
		for (int x = 1; x <= n; x++) {
			if (n % x == 0)
				cnt++;
		}
	}
	if (cnt == 2)
		return 1;
	else
		return 0;
}