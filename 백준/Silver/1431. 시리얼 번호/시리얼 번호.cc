#include<iostream>
#include<algorithm>

using namespace std;
int len;
string a[20000];
int sum1(string ab) {
	int sum = 0;
	int length = ab.length();
	for (int x = 0; x < length; x++) {
		if (ab[x] - '0' <= 9 && ab[x] >= 0) {
			sum += ab[x] - '0';
		}

	}
	return sum;

}
bool compare(string a, string b) {
	if (a.length() < b.length())
		return 1;
	else if (a.length() > b.length())
		return 0;
	else {
		int asum = sum1(a);
		int bsum = sum1(b);
		if (asum != bsum)
			return asum < bsum;
		else
			return a < b;
	}
}
int main() {

	cin >> len;
	for (int x = 0; x < len; x++)
		cin >> a[x];
	sort(a, a + len, compare);
	for (int x = 0; x < len; x++) {
		if (x > 0 && a[x] == a[x - 1])
			continue;

		else
			cout << a[x] << endl;
	}

}