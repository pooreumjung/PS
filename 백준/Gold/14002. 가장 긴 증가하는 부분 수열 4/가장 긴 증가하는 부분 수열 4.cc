#include<iostream>
#include<stack>
using namespace std;
int arr[1001];
int dp[1001];
int index = 0;
int  print(int a,int n) {
	int res = 0;
	for (int x = n; x >0; x--) {
		if (dp[x] == a) {
			return arr[x];
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for (int x = 1; x <= n; x++) {
		cin >> arr[x];
		dp[x] = 1;
	}
	for (int x = 1; x <= n; x++) {
		for (int y = 0; y < x; y++) {
			if (arr[x] > arr[y])
				dp[x] = max(dp[x], dp[y] + 1);
		}

	}
	int max1 = -987654321;
	for (int x = 1; x <= n; x++) {
		if (max1 < dp[x]) {
			max1 = dp[x];
		}
	}
	cout << max1 << endl;
	int count = 1;
	int dx = 0;
	stack<int>s;
	for (int i = n; max1 > 0; i--)
	{
		if (dp[i] == max1)
		{
			s.push(arr[i]);
			max1--;
		}
	}


	while (!s.empty()) {
		cout << s.top() << " ";
		s.pop();
	}
}
