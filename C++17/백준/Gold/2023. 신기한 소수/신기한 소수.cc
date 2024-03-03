#include<iostream>
#include<vector>
using namespace std;

int N;
void dfs(int num, int jari);
bool isprime(int num);

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	dfs(2, 1);
	dfs(3, 1);
	dfs(5, 1);
	dfs(7, 1);
}

void dfs(int num, int jari) {
	
	if (jari == N) {
		if (isprime(num)) // 진라면
			cout << num << '\n';
		return;
	}

	for (int i = 1; i <= 9; i += 2) {
		int number = 10 * num + i;
		if (isprime(number))
			dfs(number, jari + 1);
	}
	
}

bool isprime(int num) {

	for (int i = 2; i <= num / 2; i++) {
		if (num % i == 0)
			return false;
	}
	return true;
}