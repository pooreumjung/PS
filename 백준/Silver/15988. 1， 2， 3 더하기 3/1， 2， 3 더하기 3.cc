#include<iostream>
using namespace std;
unsigned long long dp[1000001] = { 0,1,2,4 };
unsigned long long find(int a);
int main() {
	int t;
	cin >> t;
	for (int x = 0; x < t; x++) {
		int n;
		cin >> n;
		cout << find(n) << "\n";
	}
}
unsigned long long find(int a) {
	if (a <= 3)
		return dp[a];
	if (dp[a] != 0)
		return dp[a];
	return dp[a] = (find(a - 2) + find(a - 3) + find(a - 1))% 1000000009;

}