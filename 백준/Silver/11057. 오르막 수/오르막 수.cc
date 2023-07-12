#include<iostream>
using namespace std;
int arr[1001][10];
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int a;
	cin >> a;
	for (int x = 0; x <=a; x++) {
		arr[9][x] = 1;
	}
	for (int x = 0; x < 10; x++)
		arr[x][0] = 1;

	for (int i = 8; i >=0; i--) {
		for (int j = 1; j <=a; j++) {
			arr[i][j] = (arr[i + 1][j] + arr[i][j - 1])%10007;
		}
	}
	cout << arr[0][a];
}

