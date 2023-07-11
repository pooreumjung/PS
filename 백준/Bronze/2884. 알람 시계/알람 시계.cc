#include<iostream>
using namespace std;
int main() {
	int a, b;
	cin >> a >> b;
	if (a > 0) {
		if (b >=45)
			cout << a << " " << b - 45;
		if (b <= 44)
			cout << a - 1 << " " << (b + 60) - 45;
	}
	if (a == 0) {
		if (b >= 45)
			cout << 0 << " " << b - 45;
		if (b <= 44)
			cout << 23 << " " << (b + 60) - 45;
	}

}