#include<iostream>
using namespace std;
int main() {
	int a, b, c;
	while (1) {
		cin >> a >> b >> c;
		if (a == 0 && b == 0 && c == 0)
			break;
		a = a * a;
		b = b * b;
		c = c * c;
		if (a + b == c || b + c == a || a + c == b)
			cout << "right" << "\n";
		else
			cout << "wrong" << "\n";
	}

}
