#include<iostream>
#include<cmath>
using namespace std;

long long arr[2][10001];
int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> arr[0][i]; // x
		cin >> arr[1][i]; // y
	}

	long long sumplus = 0;
	long long summinus = 0;
	for (int i = 1; i <= N ; i++) {
		long long a = 0;
		if (i == N) {
			a = arr[0][N] * arr[1][1];
		}
		else {
			 a = arr[0][i] * arr[1][i + 1];
		}
		sumplus += a;
	}
	for (int i = 1; i <= N; i++) {
		long long a = 0;
		if (i == N) {
			a = arr[0][1] * arr[1][N];
		}
		else {
			a = arr[0][i + 1] * arr[1][i];
		}
		summinus += a;
	}
	long long result = abs(sumplus - summinus);
	double res = (double)result;
	printf("%.1f", res/2);
}