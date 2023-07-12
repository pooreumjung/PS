#include<iostream>
using namespace std;
int arr[10001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n>>m;
	int count = 0, sum = 0, en = 0;
	for (int x = 0; x < n; x++)
		cin >> arr[x];
	for (int st = 0; st < n; st++) {
		en = st; 
		sum = 0;
		while (en < n && sum < m) {
			sum += arr[en];
			if (sum >= m)
				break;
			en++;
		}
		if (sum == m)
			count++;
	}
	cout << count;
}