#include<iostream>
using namespace std;
int arr[101][101];
int res[101][101];
void floyd(int n) {
	for (int x = 0; x < n; x++) {
		for (int y = 0; y < n; y++) {
			res[x][y] = arr[x][y];
		}
	}
	for (int k = 0; k < n; k++) {
		for (int i = 0; i <n; i++) {
			for (int j = 0; j < n; j++) {
				if (res[i][j] > res[i][k] + res[k][j])
					res[i][j] = res[i][k] + res[k][j];
			}
		}
	}
	for (int x = 0; x < n; x++) {
		for (int y = 0; y < n; y++) {
			if (x == y)
				cout << 0 << " ";
			else if (res[x][y] == 9999999)
				cout << 0 << " ";
			else
				cout << res[x][y] << " ";
		}
		cout << '\n';
	}
}
int main() {
	int n, m;
	cin >> n >> m;
	for (int x = 0; x < m; x++) {
		int a, b, c;
		cin >> a >> b >> c;
		if (arr[a-1][b-1] != 0) {
			arr[a-1][b-1] = min(arr[a-1][b-1], c);
		}
		else
			arr[a-1][b-1] = c;
	}
	for (int x = 0; x < n; x++) {
		for (int y = 0; y < n; y++) {
			if (arr[x][y] == 0)
				arr[x][y] = 9999999;
		}
	}
	floyd(n);
}

