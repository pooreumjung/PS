#include<iostream>
#include<algorithm>
using namespace std;
int arr[100005];
int n, m;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int x = 0; x < n; x++)
		cin >> arr[x];
	int en = 0, sum = arr[0];
	int ans = 987654321;
	for (int st = 0; st < n; st++) {
		while (en < n && sum < m) {
			en++;
			if (en != n)
				sum += arr[en];
		}
		if (en == n)
			break;
		ans = min(ans, en - st + 1);
		sum -= arr[st];
	}
    if(ans==987654321)
        ans=0;
	cout << ans;
}
