#include<iostream>
#include<vector>
using namespace std;


bool dp[2001][2001] = { false, };
int arr[2001];
int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	for (int i = 1; i <= n - 1; i++) {
		if (arr[i] == arr[i + 1])
			dp[i][i + 1] = true;
	}
	for (int i = 1; i <= n; i++)
		dp[i][i] = true;
	for (int i = n - 1; i >= 1; i--) {
		for (int j = i + 2; j <= n; j++) {
			if (arr[i] == arr[j] && dp[i + 1][j - 1] == true)
				dp[i][j] = true;
		}
	}
	int m, s, e;
	cin >> m;

	for (int i = 0; i < m; i++) {
		cin >> s >> e;
		cout << dp[s][e] << '\n';
	}
}