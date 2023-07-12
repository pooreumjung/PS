#include<iostream>
using namespace std;
char str[1000];
int n;
void abc(int x) {
	for (int c = 0; c < n; c++) {

		if (str[x] != 'a')
			cout << str[c];
		else
			cout << " ";
	}
	cout << endl;
}
int main() {
	cin >> n;
	for (int x = 0; x < n; x++)
		str[x] = '*';
	for (int x = 0; x < n; x++) {
		abc(x);
		str[x] = ' ';
	}
}