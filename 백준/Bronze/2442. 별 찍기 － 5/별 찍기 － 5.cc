#include <iostream>

using namespace std;

int main() {
	int a;
	cin >> a;
	for (int i = 1; i < a+1; i++) {

		for (int k = a; k > i; k--) {
			cout << " ";
		}
		for (int j = 0; j < i-1; j++) {
			cout << "*";
		}
		for (int k = 0; k < i; k++) {
			cout << "*";
		}
		cout << "\n";
	}
}