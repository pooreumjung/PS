#include<iostream>
#include<math.h>
using namespace std;
int main() {
	long long int sum = 0;
	for (int x = 0; x < 5; x++) {
		long long int input;
		cin >> input;
		long long res = input * input;
		sum += res;
	}
	cout << sum % 10;

}