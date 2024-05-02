#include<iostream>
using namespace std;
#define mod 1000000007
int dp[1010][1010] = { 0 };
int main(void)
{
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	cout.tie(NULL);
	int n, i, j, x, ans = 1;
	dp[1][1] = 1;
	cin >> n;
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			cin >> x;
			if (i != 1 || j != 1) dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % mod;
			ans += dp[i][j];
			ans %= mod;
		}
	}
	cout << ans << ' ' << n * n;
}
