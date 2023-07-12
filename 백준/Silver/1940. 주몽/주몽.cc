#include<iostream>
#include<algorithm>
int arr[15001];
using namespace std;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int x = 0; x < n; x++) 
		cin >> arr[x];
	sort(arr, arr + n);
	int left = 0, right = n - 1,count=0;
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

