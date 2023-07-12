#include<iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int a, b, c;
	cin >> a >> b >> c;
	int sum = c,count=1;
	sum -= a;
	int dif = a - b;
	if (sum <= 0) {
		cout << 1;
		return 0;
	}
	else {
		if (sum % dif == 0) {
			int flag = sum / dif;
			count += flag;
		}
		else {
			int flag = sum / dif;
			count = count + flag + 1;
		}
	}
	cout << count;
}