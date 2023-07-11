#include<iostream>
using namespace std;
int n;
int main() {
	cin >> n;
	int cnt = 0;
	for (int x = 1; x <= n; x++){
		if (x < 10) {
			cnt++;
		}
		else if (x < 100) {
			cnt++;
		}
		else if (x < 1000) {
			int a = x / 100;
			int b = (x % 100) / 10;
			int c = x % 10;
			if (b - a == c - b)
				cnt++;
		}
		else
			cnt += 0;
	}
	cout << cnt;
}