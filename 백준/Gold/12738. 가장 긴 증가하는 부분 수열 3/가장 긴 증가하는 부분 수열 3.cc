#include<iostream>
using namespace std;

int N,maxlength;
int A[1000001];
int D[1000001];
int B[1000001];
int binarysearch(int l, int r, int now);
int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> A[i];

	B[++maxlength] = A[1];
	D[1] = 1;
	int index;

	for (int i = 2; i <= N; i++) {
		if (A[i] > B[maxlength]) {
			B[++maxlength] = A[i];
			D[i] = maxlength;
		}
		else {
			index = binarysearch(1, maxlength, A[i]);
			B[index] = A[i];
			D[i] = index;
		}
	}
	cout << maxlength;
}
int binarysearch(int l, int r, int now) {
	int mid;
	while (l < r) {
		mid = (l + r) / 2;
		if (B[mid] < now) {
			l = mid + 1;
		}
		else
			r = mid;
	}
	return l;

}