#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
int dp[10001] = { 1,1,2,3 };
int find(int a);
int main() {
	for (int x = 4; x < 10001; x++) {
		dp[x] = dp[x - 1] + (dp[x - 2] - dp[x - 3]);
		if (x % 3 == 0)
			dp[x] += 1;
	}
	int t;
	scanf("%d", &t);
	for (int x = 0; x < t; x++) {
		int n;
		scanf("%d", &n);
		cout << dp[n] << "\n";
	}
}
