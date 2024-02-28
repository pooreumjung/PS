#include<iostream>
using namespace std;
int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int start_index = 1;
	int end_index = 1;
	int sum = 1;;
	int count = 1;

	int N;
	cin >> N;

	while (end_index != N) {

		if (sum == N) {
			end_index++;
			sum = sum + end_index;
			count++;
		}

		else if (N > sum) {
			end_index++;
			sum = sum + end_index;
		}

		else {
			sum = sum - start_index;
			start_index++;
		}

	}

	cout << count;
}