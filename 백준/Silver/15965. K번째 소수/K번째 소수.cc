#include<iostream>
using namespace std;
int number = 500000;
int a[500001];
int b[500001];
void prime() {
	for (int x = 2; x <= number; x++) {
		a[x] = x;
	}
	for (int x = 2; x <= number; x++) {
		if (a[x] == 0)
			continue;
		for (int y = x + x; y <= number; y += x)
			a[y] = 0;
	}
	int count = 1;
	for (int x = 2; x <= number; x++) {
		if (a[x] != 0) {
			b[count] = a[x];
			count++;
		}
			
	}
}
int main() {
	int n;
	cin >> n;
	prime();
	cout << b[n];
}
