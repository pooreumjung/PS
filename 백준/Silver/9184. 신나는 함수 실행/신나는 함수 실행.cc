#include<iostream>
using namespace std;
int w(int a, int b, int c);
int dp[21][21][21];
int main() {
	while (1) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a == -1 && b == -1 && c == -1)
			break;
		int len = w(a, b, c);
		cout << "w(" << a << ", " << b << ", " << c << ") = " << len << "\n";
	}

}
int w(int a, int b, int c) {
	if (a <= 0 || b <= 0 || c <= 0)
		return 1;
	if (a > 20 || b > 20 || c > 20) {
		return w(20, 20, 20);
	}
	if (dp[a][b][c] != 0)
		return dp[a][b][c];
	if (a < b && b < c) {
		return dp[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
	}
	else {
		return dp[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
	}
}