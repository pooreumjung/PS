#include<iostream>
using namespace std;
int dp[11] = { 0,1,2,4,7,13,24,44,81,149,274 };
int main() {
	int t;
	cin >> t;
	for (int x = 0; x < t; x++) {
		int n;
		cin >> n;
		cout << dp[n] << "\n";
	}
}
