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
		dp[x] = arr[x];
	}
	for (int x = 0; x < a; x++) {
		for (int y = 0; y < x; y++) {
			if (arr[x] > arr[y])
				dp[x] = max(dp[x], arr[x] + dp[y]);
		}
	}
	int max1 = -987654321;
	for (int x = 0; x < a; x++) {
		if (dp[x] > max1)
			max1 = dp[x];
	}
	cout << max1;
}

