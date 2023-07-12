#include<iostream>
using namespace std;
int arr[200001];
int main() {
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	for (int x = 0; x < n; x++)
		cin >> arr[x];
	long long int sum = 0,max=-987654321;
	for (int x = 0; x < n; x++) {
		if (x < k)
			sum += arr[x];
		else
			sum = sum - arr[x - k] + arr[x];
		if (x >= k - 1) {
			if (max < sum)
				max = sum;
		}

	}
	cout << max;
}