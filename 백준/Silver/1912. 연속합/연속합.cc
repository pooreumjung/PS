#include<iostream>
using namespace std;
int arr[100001];
int dp[100001];
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int a;
	cin >> a;
	for (int x = 0; x < a; x++)
		cin >> arr[x];
	int max1 = -987654321;
	for (int x = 0; x < a; x++) {
		if (x == 0) {
			dp[x] = arr[0];
			if (dp[x] > max1)
				max1 = dp[x];
		}
		else {
			dp[x] = max(arr[x], dp[x - 1] + arr[x]);
			if (dp[x] > max1)
				max1 = dp[x];
		}
	}
	cout << max1;
}