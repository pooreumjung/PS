#include<iostream>
using namespace std;
int main() {
	int len;
	cin >> len;
	char arr[100];
	int sum = 0;
	for (int x = 0; x < len; x++) {
		cin >> arr[x];
		sum += arr[x] - '0';
	}
	cout << sum;

}