#include<iostream>
#include<algorithm>
#include<vector>
#include<math.h>
using namespace std;
int arr[4000005] = { 0,1 };
int n, m;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	vector<int>v;
	for (int x = 1; x <= sqrt(4000005); x++) {
		if (arr[x] != 0)
			continue;
		for (int y = x * x; y <= 4000005; y += x)
			arr[y] = 1;
	}
	for (int x = 2; x <= n; x++) {
		if (arr[x] == 0)
			v.push_back(x);
	}
	int en = 0, count = 0;
	int sum = 0;
	for (int st = 0; st < v.size(); st++) {
		sum = 0;
		en = st;
		while (en < v.size() && sum < n) {
			sum += v[en];
			if (sum == n)
				break;
			en++;
		}
		if (sum == n)
			count++;
	}
	cout << count;
}
