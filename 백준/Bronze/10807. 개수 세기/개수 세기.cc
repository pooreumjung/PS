#include<iostream>
using namespace std;
int arr[202] = { 0 };
int main() {
	int n;
	cin >> n;
	for (int x = 0; x < n; x++) {
		int input;
		cin >> input;
		arr[input + 100]++;
	}
	int find,res=0;
	cin >> find;
	for (int x = 0; x < 202; x++) {
		if (arr[x] > 0 && x - 100 == find) {
			res = arr[x];

		}

	}
	cout << res;
}