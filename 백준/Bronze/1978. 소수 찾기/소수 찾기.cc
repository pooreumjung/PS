#include<iostream>
using namespace std;
int find(int n);
int main() {
	int n;
	cin >> n;
	int sum = 0;
	for (int x = 0; x < n; x++) {
		int a;
		cin >> a;
		int res = find(a);
		sum += res;
	}
	cout << sum;

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