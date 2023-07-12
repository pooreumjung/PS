#include<iostream>
#include<math.h>
using namespace std;
int arr[10000001];
int max1 = 10000000;
int find(int a) {
	int n = a;
	int sum = 0;
	while (1) {
		int x = n % 10;
		n /= 10;
		sum += x;
		if (n == 0)
			break;
		
		sum *= 10;
	}
	if (a == sum)
		return 1;
	else
		return -1;

}
int main() {
	for (int x = 2; x <= sqrt(max1); x++) {
		if (arr[x] != 0)
			continue;
		for (int y = x * x; y <= max1; y += x)
			arr[y] = 1;
	}
	int a, b,flag=0;
	cin >> a >> b;
	for (int x = a; x <= b; x++) {
		if (x >= 10000000)
			break;
		flag = -1;
		if (arr[x] == 0) {
			flag = find(x);
			if (flag == 1)
				cout << x << endl;
		}
	}
	cout << -1;


}