#include<iostream>
using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long x1, y1, x2, y2, x3, y3;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

	long sum1 = x1 * y2 + x2 * y3 + x3 * y1;
	long sum2 = y1 * x2 + y2 * x3 + y3 * x1;

	if (sum1 - sum2 < 0)
		cout << -1;
	else if (sum1 - sum2 == 0)
		cout << 0;
	else
		cout << 1;

}