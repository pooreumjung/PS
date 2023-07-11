#include<iostream>
using namespace std;
unsigned long long dp[1000001] = { 0,1,2,3 };
int main() {
	int n;
	cin >> n;
	if (n == 1 || n == 2)
		cout << n;
	else {
		for (int x = 3; x <= n; x++)
			dp[x] = (dp[x - 2] + dp[x - 1])%15746;
		cout << dp[n];
	}
}