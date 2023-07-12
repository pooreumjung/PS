#include <iostream>

using namespace std;

long long memo[101][10], sol;
int N;

int main() {
	cin >> N;
	
	for (int i = 1; i < 10; i++)
		memo[1][i] = 1;

	for (int i = 2; i <= N; i++) {
		for (int j = 0; j < 10; j++) {
			if (j == 0)
				memo[i][j] += memo[i - 1][j + 1] % 1000000000;
			else if (j == 9)
				memo[i][j] += memo[i - 1][j - 1] % 1000000000;
			else {
				memo[i][j] += memo[i - 1][j - 1] % 1000000000;
				memo[i][j] += memo[i - 1][j + 1] % 1000000000;
			}
		}
	}

	for (int i = 0; i < 10; i++)
		sol += memo[N][i] % 1000000000;

	cout << sol % 1000000000;
}
