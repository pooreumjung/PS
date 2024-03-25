#include<iostream>
using namespace std;

int N, maxlength;
int B[1000001];
int A[1000001];
int D[1000001];
int ans[1000001];
int binarysearch(int l, int r, int now);
int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> A[i];

	int index;
	B[++maxlength] = A[1];
	D[1] = 1;

	for (int i = 2; i <= N; i++) {
		if (B[maxlength] < A[i]) {
			B[++maxlength] = A[i];
			D[i] = maxlength;
		}
		else {
			index = binarysearch(1, maxlength, A[i]);
			B[index] = A[i];
			D[i] = index;
		}
	}
	cout << maxlength << '\n';
	index = maxlength;
	int x = B[maxlength] + 1;

	for (int i = N; i >= 1; i--) {
		if (D[i] == index && A[i] < x) {
			ans[index] = A[i];
			x = A[i];
			index--;
		}
	}

	for (int i = 1; i <= maxlength; i++)
		cout << ans[i] << " ";

}
int binarysearch(int l, int r, int now) {
	int mid;

	while (l < r) {
		mid = (l + r) / 2;
		if (B[mid] < now)
			l = mid + 1;
		else
			r = mid;
	}
	return l;
}
