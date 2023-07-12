#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
using namespace std;
int main() {
	char a[8];
	char b[8] = { 0, };
	char c[8] = { 0, };
	char d[8] = { 0, };
	int n;
	cin >> n;
	int index=0;
	for (int x = 0; x < n; x++) {
		cin >> a;
		strcpy(b, a);
		for (int x = 0; x < strlen(a) / 2; x++)
			swap(a[x], a[strlen(a) - x - 1]);
		int flag = 0, sum = 0;
		for (int x = 0; !(a[x] == 0 && b[x] == 0); x++) {
			sum += a[x] - '0' + b[x] - '0' + flag;
			if (sum >= 10) {
				flag = 1;
				sum -= 10;
				c[x] = sum + '0';
			}
			else {
				flag = 0;
				c[x] = sum + '0';
			}
			sum = 0;
			index = x;
		}
	int end;

	if (flag) {
		c[index] = flag+'0';
		end = index + 1;
	}
	else end = index;
		strcpy(d, c);
		for (int x = 0; x < strlen(c) / 2; x++)
			swap(c[x], c[strlen(c) - x - 1]);
		if (strcmp(d, c) == 0)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
		for (int x = 0; x < 8; x++) {
			b[x] = 0;
			c[x] = 0;
			d[x] = 0;
		}
	}
}
