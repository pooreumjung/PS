#include<iostream>
#include<algorithm>

using namespace std;
int len;
string a[20000];
bool compare(string a, string b) {
	if (a.length() < b.length())
		return 1;
	else if (a.length() > b.length())
		return 0;
	else {
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