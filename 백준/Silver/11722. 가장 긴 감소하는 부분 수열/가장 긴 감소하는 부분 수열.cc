#include<iostream>
using namespace std;
int arr[1001];
int dp[1001];
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int a;
	cin >> a;
	for (int x = 0; x < a; x++) {
		cin >> arr[x];
		dp[x] = 1;
	}
	
	int max1 = -987654321;
	int max2 = -987654321;
	max2 = arr[0];
	for (int i = 1; i < a; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[i] <arr[j])
				dp[i] = max(dp[j] + 1, dp[i]);
		}
	}
	for (int x = 0; x < a; x++) {
		if (max1 < dp[x])
			max1 = dp[x];
	}
	
		cout << max1;
}