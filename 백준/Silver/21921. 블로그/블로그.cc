#include<iostream>
using namespace std;
int arr[250001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,k;
	cin >> n>>k;
	for (int x = 0; x < n; x++)
		cin >> arr[x];
	int sum = 0,max=-987654321,count=1;
	for (int x = 0; x < n; x++) {
		if (x < k)
			sum += arr[x];
		else
			sum = sum - arr[x - k] + arr[x];
		if (max == sum)
			count++;
		if (x >= k - 1) {
			
			if (max < sum) {
				max = sum;
				count = 1;
			}
		}
	}
	if (max == 0)
		cout << "SAD";
	else
		cout << max << endl << count;
}