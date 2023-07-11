#include<iostream>
using namespace std;
int main() {
	int arr[1001];
	int n,temp=0;
	cin >> n;
	for (int x = 0; x < n; x++)
		cin >> arr[x];
	for (int x = 0; x < n; x++) {
		for (int y = x + 1; y < n; y++) {
			if (arr[x] > arr[y]) {
				temp = arr[x];
				arr[x] = arr[y];
				arr[y] = temp;
			}
		}
	}
	for (int x = 0; x < n; x++)
		cout << arr[x] << "\n";
}