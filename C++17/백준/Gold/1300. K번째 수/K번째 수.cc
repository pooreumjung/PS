#include<iostream>
using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long N, K;
	cin >> N >> K;

	long start = 1;
	long end = K;
	long ans = 0;

	while (start <= end) {
		long middle = (start + end) / 2;
		long cnt = 0;
		for (int i = 1; i <= N; i++) {
			cnt += min((middle / i), N);
		}
		if (cnt < K)
			start = middle + 1;
		else {
			end = middle - 1;
			ans = middle;
		}
	}
	cout << ans;
}