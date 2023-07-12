#include<iostream>
using namespace std;
char arr[101] = { 0, };
int n;
void abc(int a) {
	arr[n + a] = '*';
	arr[n - a] = '*';
	for (int x = 1; x <= n + a; x++) {
		if (arr[x] == '*')
			cout << '*';
		else
			cout << " ";
	}
	cout << endl;
}
int main() {
	cin >> n;
	for (int x = 0; x < n; x++) {
		abc(x);
	}
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < i; j++) {
			cout << ' ';
		}
		for (int b = i + 1; b < n * 2 - i; b++) {
			cout << '*';
		}
		cout << endl;
	}
	return 0;
}