#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<int>arr;
int main() {
	int n;
	int k;
	cin >> n >> k;
	for (int x = 0; x < 10000; x++) {
		int d = x * x;
		if (d > 10000)
			break;
		arr.push_back(d);
	}
	sort(arr.begin(), arr.end());
	int count = 0, res, sum = 0;;
	for (int x = 0; x < arr.size(); x++) {
		if (count == 0 && arr[x] >= n && arr[x] <= k) {
			count++;
			res = arr[x];
			sum += res;
		}
		else if (count > 0 && arr[x] >= n && arr[x] <= k) {
			count++;
			sum += arr[x];
		}
	}
	if (count >= 1)
		cout << sum << endl << res;
	else
		cout << -1;
}