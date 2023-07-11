#include<iostream>
using namespace std;
int arr[100][100];
int arr2[100][100];
int n, m;
int main() {
	cin >> n >> m;
	for (int x = 0; x < n; x++) {
		for (int y = 0; y < m; y++) {
			cin >> arr[x][y];
		}
	}
	for (int x = 0; x < n; x++) {
		for (int y = 0; y < m; y++) {
			cin >> arr2[x][y];
		}
	}
	for (int x = 0; x < n; x++) {
		int sum = 0;
		for (int y = 0; y < m; y++) {
			int dx = arr[x][y] + arr2[x][y];
			cout << dx << " ";
		}
		cout <<endl;
	}
}