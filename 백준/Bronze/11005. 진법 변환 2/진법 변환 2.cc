#include <iostream>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int b, n;
	string sum ="";
	cin >> n >> b;

	while (n!=0) {
		int tmp = n % b;
		n = n / b;
		if (tmp < 10) sum += (tmp + '0');
		else sum += (tmp + 'A' - 10);
	}

	for (int i =0; i < sum.length(); i++) {
		cout << sum[sum.length() - i - 1];
	}
	cout << '\n';
	return 0;
}