#include <iostream>
using namespace std;
int N, K;
int dp[1001][1001];
void sol() {
	if (N == 0) {
		cout << 0 << endl;
		return;
	}
	for (int x = 1; x <= N; x++) {
		for (int y = 0; y <= K; y++) {
			if (y == 0)
				dp[x][y] = 1;
			else if (x == y)
				dp[x][y] = 1;
			else
				dp[x][y] = dp[x - 1][y - 1] + dp[x - 1][y];
			dp[x][y] %= 10007;
		}


	}
	cout << dp[N][K] % 10007;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> K;
	sol();


}


