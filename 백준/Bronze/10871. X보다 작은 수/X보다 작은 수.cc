#include<iostream>
using namespace std;
int main() {
	int n, x, a;
	cin >> n >> x;
	for (int k = 0; k < n; k++) {
		cin >> a;
		if (a < x)
			cout << a << " ";
	}

}