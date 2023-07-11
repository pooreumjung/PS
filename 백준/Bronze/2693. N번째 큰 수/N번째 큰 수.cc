#include<iostream>
using namespace std;
int arr[10];
int n = 10;
int num;
int main() {
	cin >> num;
	for (int x = 0; x < num; x++) {
		for (int x = 0; x < n; x++)
			cin >> arr[x];
		for (int x = 1; x < n; x++) {
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
		for (int x = n - 1; x >= 0; x--) {
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
		cout << arr[7]<<"\n";
	}
}