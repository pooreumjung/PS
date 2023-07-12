#include<iostream>
#include<math.h>
using namespace std;
int arr[100001] = { 1,1 };
int cou[100001];
void clear(int a) {
	for (int x = 2; x <= a; x++)
		arr[x] = 0;
}

void print(int a) {
	int count = 0;
	int m = a;
	for (int x = 2; x <= a; x++) {
		if (m % x == 0) {
			cou[x]++;
			m /= x;
			x--;
		}
	}
	for (int x = 2; x <= a; x++) {
		if (cou[x] != 0) {
			cout << x << " " << cou[x] << endl;
			cou[x] = 0;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
		for (int x = 2; x <= sqrt(100001); x++) {
			if (arr[x] != 0)
				continue;
			for (int y = x * x; y <= 100001; y += x) {
				arr[y] = 1;
			}
		}
	for (int x = 0; x < n; x++) {
		int a;
		cin >> a;
		print(a);
		clear(a);
	}
}
