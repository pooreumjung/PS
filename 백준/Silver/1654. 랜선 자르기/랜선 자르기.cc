#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long N, M;
	cin >> N >> M;

	vector<long>A(N, 0);
	for (long i = 0; i < N; i++)
		cin >> A[i];

	sort(A.begin(), A.end());
	long end = A[N - 1];
	long start =1;
	long ans = 0;
		
	while (start <= end) {
		long middle = (start + end) / 2;
		long high = 0;
		for (long i = 0; i < N; i++) {
			if(middle!=0)
			high += A[i] / middle;
		}

		if (high < M) {
			end = middle - 1;
		}
		else {
			start = middle + 1;
			if(middle>ans)
			ans = middle;
		}
	}
	cout << ans;
}

