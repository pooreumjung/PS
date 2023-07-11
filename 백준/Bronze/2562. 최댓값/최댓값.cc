#include<iostream>
using namespace std;
int main() {
	int arr[9];
	int max = 0,dx=0;
	for (int x = 0; x < 9; x++) {
		cin >> arr[x];
		if (max < arr[x]) {
			max = arr[x];
			dx = x;
		}
	}
	cout << max << "\n" << dx+1 ;
}