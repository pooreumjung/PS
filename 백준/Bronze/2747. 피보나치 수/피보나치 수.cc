#include<iostream>
using namespace std;
int fibo(int a);
int dp[46] = { 0,1,1 };
int main() {
	int n;
	cin >> n;
	cout << fibo(n);
}
int fibo(int a) {
	if (a == 1 || a == 2)
		return 1;
	if (dp[a] != 0)
		return dp[a];
	return dp[a] = fibo(a - 2) + fibo(a - 1);

}