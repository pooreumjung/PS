#include<iostream>
using namespace std;
int main() {
	int a, b;
	cin >> a >> b;
	a = (a / 100) + (a % 10) * 100 + ((a % 100) / 10) * 10;
	b = (b / 100) + (b % 10) * 100 + ((b % 100) / 10) * 10;
	if (a > b)
		cout << a;
	if (a < b)
		cout << b;

}