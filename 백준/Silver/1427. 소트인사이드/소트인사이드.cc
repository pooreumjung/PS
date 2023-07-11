#include<iostream>
using namespace std;
int arr[10];
int n = 10;
int num;
int main() {
	cin >> num;
	int dx = 0;
	while (num != 0) {
		arr[dx] = num % 10;
		num = num / 10;
		dx += 1;
	}
				for (int x = 1; x < dx; x++) {
			int c = x;
			do {
				int root = (c - 1) / 2;
				if (arr[root] < arr[c]) {
					int temp = arr[root];
					arr[root] = arr[c];
					arr[c] = temp;
				}
				c = root;
			} while (c != 0);
		}
		for (int x = dx - 1; x >= 0; x--) {
			int temp = arr[0];
			arr[0] = arr[x];
			arr[x] = temp;
			int root = 0;
			int c = 1;
			do {
				c = 2 * root + 1;
				if (arr[c] < arr[c + 1] && c < x - 1)
					c++;
				if (arr[root] < arr[c] && c < x) {
					int temp = arr[root];
					arr[root] = arr[c];
					arr[c] = temp;
				}
				root = c;
			} while (c < x);
		}
		for (int x = dx - 1; x >= 0; x--)
			cout << arr[x];
}