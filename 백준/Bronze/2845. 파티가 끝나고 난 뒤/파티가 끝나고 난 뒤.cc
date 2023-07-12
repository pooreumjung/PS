#include<iostream>
using namespace std;
int main() {
	int person,a;
	cin >> person>>a;
	int res = a * person;
	for (int x = 0; x < 5; x++) {
		int c;
		cin >> c;
		cout << c-res<<" ";
	}
}