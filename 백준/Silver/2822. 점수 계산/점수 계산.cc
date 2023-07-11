#include<iostream>
int arr[8];
using namespace std;

void quick(int a[], int start, int end);
int main() {
	int res[5];
	int arr2[8];
	for (int x = 0; x < 8; x++)
		cin >> arr[x];
	for (int x = 0; x < 8; x++)
		arr2[x] = arr[x];
	quick(arr2, 0, 7);
	int sum = 0;
	for (int x = 7; x >= 3; x--)
		sum += arr2[x];
	cout << sum<<endl;
	for (int x = 0; x < 8; x++) {
		if (arr2[7] == arr[x]) {
			int cnt = x + 1;
			res[4] = cnt;
		}
	}
	for (int x = 0; x < 8; x++) {
		if (arr2[6] == arr[x]) {
			int cnt = x + 1;
			res[3] = cnt;
		}
	}
	for (int x = 0; x < 8; x++) {
		if (arr2[5] == arr[x]) {
			int cnt = x + 1;
			res[2] = cnt;
		}
	}
	for (int x = 0; x < 8; x++) {
		if (arr2[4] == arr[x]) {
			int cnt = x + 1;
			res[1] = cnt;
		}
	}
	for (int x = 0; x < 8; x++) {
		if (arr2[3] == arr[x]) {
			int cnt = x + 1;
			res[0] = cnt;
		}
	}
	quick(res, 0, 4);
	for (int x = 0; x < 5; x++)
		cout << res[x] << " ";
}
void quick(int a[], int start, int end) {
	int key = start;
	int i = start + 1;
	int j = end;
	if (start >= end)
		return;
	while (i <= j) {
		while (a[i] <= a[key])
			i++;
		while (a[j] >= a[key]&&j>start)
			j--;
		if (i > j)
			swap(a[j], a[key]);
		else
			swap(a[j], a[i]);
	}
	quick(a, start, j - 1);
	quick(a, j + 1, end);
}