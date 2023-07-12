#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;

	int count = 1;
	for (auto i = 0; i < n; ++i) {
		count *= 2;
	}

	cout << count << endl;
}