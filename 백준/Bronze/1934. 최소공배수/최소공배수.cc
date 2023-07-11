#include<iostream>
using namespace std;
int find(int a, int b);
int main() {
	int a, b,n;
	cin >> n;
	for (int x = 0; x < n; x++) {
		cin >> a >> b;
		int c = find(a, b);
		cout << (a * b) / c<<"\n";
	}
}
int find(int a, int b) {
	if (a < b)
		swap(a, b);
	while (b != 0) {
		int res = a % b;
		a = b;
		b = res;
	}
	return a;
}