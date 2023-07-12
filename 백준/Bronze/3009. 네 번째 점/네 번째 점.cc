#include<iostream>
using namespace std;
int arr[1001];
int arr2[1001];
int main() {
	for (int x = 0; x < 3; x++) {
		int a, b;
		cin >> a >> b;
		arr[a]++;
		arr2[b]++;
	}
	int index,count,index1,count1;
	int index2, count2, index3, count3;
	for (int x = 0; x < 1001; x++) {
		if (arr[x] != 0) {
			if (arr[x] % 2 == 1) {
				index = x;
				count = arr[x];
			}
			else {
				index1 = x;
				count1 = arr[x];
			}
		}
	}
	for (int x = 0; x < 1001; x++) {
		if (arr2[x] != 0) {
			if (arr2[x] % 2 == 1) {
				index2 = x;
				count2 = arr2[x];
			}
			else {
				index3 = x;
				count3 = arr2[x];
			}
		}
	}
	cout << index << " " << index2;
}