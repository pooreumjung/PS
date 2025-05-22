#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define ll long long

long long Pcount[200001]; // 얘는 그냥 P의 개수
long long Ccount[200002];

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, K;
	cin >> N >> K;
	vector<char>s(N + 2);
	s[0] = s[N + 1] = 'X';

	for (int i = 1; i <= N; i++)
		cin >> s[i];

	int left = 0, right = N + 1;

	while (left < right && K) {
		while (left < N && s[left] != 'C')
			left++;
		while (right >= 0 && s[right] != 'P')
			right--;
		if (left >= right)
			break;
		K--;
		swap(s[left], s[right]);
	}

	for (int i = 1; i <= N; i++) {
		if (s[i] == 'P')
			Pcount[i] = Pcount[i - 1] + 1;
		else
			Pcount[i] = Pcount[i - 1];
	}

	for (int i = N; i >= 1; i--) {
		if (s[i] == 'C')
			Ccount[i] = Ccount[i + 1] + 1;
		else
			Ccount[i] = Ccount[i + 1];
	}

	ll ans = 0;
	for (int i = 1; i <= N; i++) {
		if (s[i] == 'P') {
			ans += Pcount[i - 1] * Ccount[i];
		}
	}
	cout << ans;
}
