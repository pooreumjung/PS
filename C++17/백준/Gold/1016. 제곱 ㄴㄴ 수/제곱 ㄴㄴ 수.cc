#include<iostream>
#include<vector>
using namespace std;

int A[1000001];

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long MIN, MAX;
	cin >> MIN >> MAX;

	vector<bool>check(MAX - MIN + 1);

	for (long i = 2; i * i <= MAX; i++) {
		long pow=i* i;
		long start = MIN / pow;

		if (MIN % pow != 0)
			start++;
		for (long j = start; j * pow <= MAX; j++) {
			check[(int)((j * pow) - MIN)] = true;
		}
	}
	int count = 0;
	for (int i = 0; i < check.size(); i++) {
		if (!check[i])
			count++;
	}
	cout << count;
}