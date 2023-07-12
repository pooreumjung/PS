#include <iostream>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int b, sum = 0;
	string n;
	cin >> n >> b;

	for (int i = 0; i < n.length(); i++) {
		int tmp = 1;
		// math 라이브러리를 사용한다면 아래 for문은 생략 가능
		for (int j = 0; j < n.length() - i - 1; j++) {
			tmp *= b;
		}

		if (n[i] >= '0' && n[i] <= '9') {
			sum += (n[i] - '0') * tmp;
		}
		else {
			sum += (n[i] - 'A' + 10) * tmp;
		}
	}

	cout << sum << '\n';

	return 0;
}