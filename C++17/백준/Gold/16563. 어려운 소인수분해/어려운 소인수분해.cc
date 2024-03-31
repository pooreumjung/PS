#include<iostream>
#include<cmath>
using namespace std;

int arr[5000001];
void isprime(int number);
int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i <= 5000000; i++)
		arr[i] = i;
	
	for (int i = 2; i * i <= 5000000; i++) {
		if (arr[i] == i) {
			for (int j = i * i; j <= 5000000; j += i) {
				if (arr[j] == j)
					arr[j] = i;
			}

		}

	}

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		isprime(num);
		cout << '\n';
	}
}
void isprime(int number) {
	while (number > 1) {
		cout << arr[number] << " ";
		number /= arr[number];
	}
}