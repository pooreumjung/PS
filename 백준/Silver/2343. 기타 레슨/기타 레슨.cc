#include<iostream>
#include<vector>
using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	vector<int>A(N, 0);
	long sum = 0;
	int start = 0;

	for (int i = 0; i < N; i++) {
		cin >> A[i];
		sum += A[i];
		if (start < A[i])
			start = A[i];
	}

	int end = sum;

	while (start <= end) {
		int middle = (start + end) / 2;
		int su = 0;
		int count = 0;
		for (int i = 0; i < N; i++) {		
			if (su+A[i] > middle) {
				su = 0;
				count++;
			}
			su += A[i];
		}
		if (sum != 0)
			count++;
	    if (count > M) {
			start = middle + 1;
		}
		else {
			end = middle - 1;
		}

	}
	cout << start;
}