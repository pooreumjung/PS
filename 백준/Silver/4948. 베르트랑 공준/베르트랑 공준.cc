#include<iostream>
using namespace std;
int a, b;
int arr[250000] = { 1,1,0 };
void find(int a, int b);
int main() {
	while (1) {
		cin >> a;
		if (a == 0)
			return 0;
		b = 2 * a;
		find(a, b);
		int sum = 0;
		for (int x = a+1; x <= b; x++) {
			if (arr[x] == 0)
				sum++;
		}
		cout << sum << "\n";
	}
	return 0;
}
void find(int a, int b) {
	for (int x = 2; x < 250000/x; x++) {
		if (arr[x] == 1)
			continue;
		for (int y = x * x; y < 250000; y += x) {
			if (y % x == 0)
				arr[y] = 1;
		}
	}

}