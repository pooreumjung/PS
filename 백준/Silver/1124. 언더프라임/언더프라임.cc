#include<iostream>
#include<math.h>
using namespace std;
int arr[100001] = { 1,1 };
void prime() {
	for (int x = 2; x <= sqrt(100001); x++) {
		for (int y = x * x; y <= 100001; y += x) {
			if (arr[y] != 0)
				continue;
			else
				arr[y] = 1;
		}
	}
}
int abc(int a) {
	int count = 0;
	for (int x = 2; x <= a; x++) {
		if (arr[x]==0&&a % x == 0) {
			a /= x;
			count++;
			x--;
		}
		if (a == 1)
			break;
	}
	return count;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int a, b;
	cin >> a >> b;
	prime();
	int sum = 0;
	for (int x = a; x <= b; x++) {
		int d = abc(x);
		if (arr[d] == 0)
			sum++;
	}
	cout << sum;
}