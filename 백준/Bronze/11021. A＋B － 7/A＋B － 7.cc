#include<iostream>
using namespace std;
int main() {
	int n,a,b;
	cin >> n;
	for (int x = 0; x < n; x++) {
		cin >> a >> b;
		cout << "Case #" << x + 1 << ": " << a + b << "\n";
	}
}