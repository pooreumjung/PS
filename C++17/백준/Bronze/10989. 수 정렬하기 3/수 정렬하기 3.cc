#include<iostream>

using namespace std;
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	int arr[10001] = { 0 };
	for (int x = 0; x < n; x++) {
		int a;
		cin >> a;
		arr[a]++;
	}
	for (int x = 0; x < 10001; x++) {
		if (arr[x] != 0) {
			for (int k = 0; k < arr[x]; k++)
				cout << x << "\n";
		}
	}
return 0;

}