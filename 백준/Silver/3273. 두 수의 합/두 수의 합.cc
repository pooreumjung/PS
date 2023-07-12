#include<iostream>
#include<algorithm>
int arr[100001];
using namespace std;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n;
	int ed = 0, count = 0, sum = 0;
	for (int x = 0; x < n; x++)
		cin >> arr[x];
	cin >> m;
	sort(arr, arr + n);
	int left=0, right=n-1;
	while (left < right) {
		if (arr[left] + arr[right] == m) {
			count++;
			left++;
			right--;
		}
		else if (arr[left] + arr[right] > m)
			right--;
		else
			left++;
	}
	cout << count;
}

