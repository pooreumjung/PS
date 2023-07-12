#include<iostream>
#include<cstring>
using namespace std;
int main() {
	long long int a, b, c;
	cin >> a >> b >> c;
	if (c <= b) {
		cout << -1;
		return 0;
	}
	else {
		cout << (a / ((abs(b - c)))) + 1;
	}
}

