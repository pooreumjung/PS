#include<iostream>
using namespace std;
int find(int a, int b);
int main() {
	int a, b;
		cin >> a >> b;
		int c = find(a, b);
		cout << c << "\n" << (a * b) / c;
	
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