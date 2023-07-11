#include <iostream>
#define MOD 1000000009
using namespace std;
long long int dp[100001][3] = { 0,0,0,1, 0, 0, 0,1,0, 1,1,1 };
int main() {
	int num, number;
	cin >> num;
	for (int i = 4; i <= 100000; i++) {
		dp[i][0] = dp[i - 1][1] + dp[i - 1][2] % MOD;
		dp[i][1] = dp[i - 2][0] + dp[i - 2][2] % MOD;
		dp[i][2] = dp[i - 3][0] + dp[i - 3][1] % MOD;
	}
	while (num--) {
		cin >> number;
		long long result = ((dp[number][0] + dp[number][1] + dp[number][2]) % MOD);
		cout << result << endl;
	}
}
