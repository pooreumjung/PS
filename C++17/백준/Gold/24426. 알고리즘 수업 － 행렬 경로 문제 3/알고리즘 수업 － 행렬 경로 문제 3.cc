#include <iostream>
using namespace std;
typedef long long ll;

int N, R, C;
ll arr[1001][1001];
ll dp[1001][1001][3];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 2; i <= N; i++) {
		arr[i][0] = arr[0][i] = -1000000007;
	}
	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= N; c++) {
			cin >> arr[r][c];
		}
	}

	cin >> R >> C;
	for (int r = 0; r <= N; r++) {
		for (int c = 0; c <= N; c++) {
			if (r) {
				if (c) {
					dp[r][c][0] = arr[r][c] + max(dp[r - 1][c][0], dp[r][c - 1][0]);
					if (r == R && c == C) {
						dp[r][c][1] = arr[r][c] + max(dp[r - 1][c][0], dp[r][c - 1][0]);
						dp[r][c][2] = -1000000007;
					}
					else {
						if (max(dp[r - 1][c][1], dp[r][c - 1][1])) dp[r][c][1] = arr[r][c] + max(dp[r - 1][c][1], dp[r][c - 1][1]);
						dp[r][c][2] = arr[r][c] + max(dp[r - 1][c][2], dp[r][c - 1][2]);
					}
				}
				else {
					dp[r][c][0] = arr[r][c] + dp[r - 1][c][0];
					if (dp[r - 1][c][1]) dp[r][c][1] = arr[r][c] + dp[r - 1][c][1];
					dp[r][c][2] = arr[r][c] + dp[r - 1][c][2];
				}
			}
			else {
				if (c) {
					dp[r][c][0] = arr[r][c] + dp[r][c - 1][0];
					if (dp[r][c - 1][1]) dp[r][c][1] = arr[r][c] + dp[r][c - 1][1];
					dp[r][c][2] = arr[r][c] + dp[r][c - 1][2];
				}
				else {
					dp[r][c][0] = dp[r][c][1] = dp[r][c][2] = 0;
				}
			}
		}
	}

	cout << dp[N][N][1] << ' ' << dp[N][N][2];
}