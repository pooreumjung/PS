#include<iostream>
using namespace std;
int arr[100];
int find(int a, int b);
int main() {
	int n;
	cin >> n;
	for (int x = 0; x < n; x++)
		cin >> arr[x];
	for (int x = 0; x < n - 1; x++) {
		int res = find(arr[0], arr[x + 1]);
		cout << arr[0] / res << "/" << arr[x + 1] / res << "\n";
	}
}
int find(int a, int b) {
	if (a < b)
		swap(a, b);
	int res = 0;
	while (b != 0) {
		res = a % b;
		a = b;
		b = res;
	}
	return a;
}