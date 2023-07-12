#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<int>arr;
int main() {
	int n, k;
	cin >> n >> k;
	int index = 0;
	for (int x = 1; x <= n; x++) {
		if (n % x == 0) {
			arr.push_back(x);
		}
	}
	sort(arr.begin(), arr.end());
	int d = k - 1;
	if (arr.size() >= k) {
		cout << arr[d];
	}
	else
		cout << 0;

}