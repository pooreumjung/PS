#include<iostream>
#include<math.h>
using namespace std;
int arr[500001] = { 1, };
int main() {
	int n;
	for (int x = 2; x <= sqrt(500001); x++) {
		for (int y = x * x; y <= 500001; y+=x) {
			if (arr[y] != 0)
				continue;
			arr[y] = 1;
		}
	}
	int count;
	while (1) {
		count = 0;
		cin >> n;
		if (n == 0)
			return 0;
		for (int x = 2; x <= n; x++) {
			if (x <= n - x && arr[x] == 0 && arr[n - x] == 0)
				count++;
		}
		cout << count << '\n';
	}

}