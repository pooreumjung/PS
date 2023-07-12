#include <iostream>
using namespace std;

int T, P, Q;
long long dp[10001]={0,1,1,};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> T;
	for (int i = 1; i <= T; i++) {
		cin >> P >> Q;
		dp[1] = 1;
		dp[2] = 1;
		for (int j = 3; j <=P; j++) {
			dp[j] = (dp[j - 1] + dp[j - 2]) % Q;
		}
		cout << "Case #" << i << ": " << dp[P] % Q << '\n';
	}
	return 0;
}
