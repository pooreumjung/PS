#include<iostream>
#include<string>
using namespace std;
int main() {
	string a, b,c;
	cin >> a >> b;
	int count = 0,flag,min=999;
	if (a.length() == b.length()) {
		for (int x = 0; x < a.length(); x++) {
			if (a[x] != b[x])
				count++;
		}
	}
	else {
		for (int x = 0; x <= b.length() - a.length(); x++) {
			flag = 0;
			for (int y = 0; y < a.length(); y++) {
				if (a[y] != b[x+y]) {
					flag++;
				}
			}
			if (flag < min) {
				min = flag;
			}
		}
		count = min;

	}
	cout << count;
}