#include<iostream>
using namespace std;
int dp[1001] = { 0,1,2 };
int find(int a);
int main() {
	int n;
	cin >> n;
	cout << find(n);
}
int find(int a) {
	if (a == 1 || a == 2)
		return a;
	if (dp[a] != 0)
		return dp[a];
	else
		return dp[a] = (find(a - 2) + find(a - 1)) % 10007;

}