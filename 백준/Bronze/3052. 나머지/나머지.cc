#include<iostream>
using namespace std;
int main() {
	int arr[42] = { 0 };
	int arr1[10];
	for (int x = 0; x < 10; x++) {
		cin >> arr1[x];
		arr[arr1[x] % 42]++;
	}
	int cnt = 0;
	for (int x = 0; x < 42; x++) {
		if (arr[x] >= 1)
			cnt++;
	}
	cout << cnt;
}