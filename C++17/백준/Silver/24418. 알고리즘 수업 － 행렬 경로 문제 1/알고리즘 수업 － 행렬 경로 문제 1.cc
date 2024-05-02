#include<iostream>
using namespace std;

int arr[16][16];
int cnt1 = 0;
int matrix(int i,int j);
int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;

	matrix(n,n);
	cout << cnt1+1 << " " << n * n;
}
int matrix(int i,int j) {
	if (i == 0 || j == 0)
		return 0;
	else {
		cnt1++;
		return max(matrix(i, j - 1), matrix(i - 1, j));
	}
}
