#include<iostream>
#include<cmath>
using namespace std;

long arr[10000001];

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 2; i <= 10000000; i++)
		arr[i] = i;

	for (int i = 2; i <= sqrt(10000001); i++) {
		if (arr[i] == 0)
			continue;
		for (int j = i + i; j <= 10000000; j += i)
			arr[j] = 0;
	}

	long A, B;
	cin >> A >> B;
	int count = 0;

	for (int i = 2; i <10000001; i++) {
		long temp = 0;
		if (arr[i] != 0) {
			long temp = i;
			while ((double)arr[i] <= (double)B / (double)temp) {
				if ((double)arr[i] >= (double)A / (double)temp) {
					count++;					
				}
				temp = temp * i;
			}
		}
	}
	cout << count;
}

