#include<iostream>
using namespace std;
int main() {
	int arr[10] = { 0 };
	int a, b, c;
	cin >> a >> b >> c;
	int i = a * b * c;
	while (i != 0) {
		arr[i % 10] += 1;
		i /= 10;
	}
	for (int x = 0; x < 10; x++)
		cout << arr[x] << "\n";
}