#include<iostream>
#include<string>
using namespace std;

int ac[26];
int cnt2[26];
int dp[200001][26];
int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string str;
	cin >> str;
	int len = str.length();
	for (int i = 0; i < len; i++) {
		char a = str[i];
		a -= 'a';
		ac[a]++;
	}
	fill(cnt2, cnt2 + 26, 1);

	int q;
	cin >> q;

	for (int i = 1; i <= len; i++) {
		char a = str[i - 1];
		a -= 'a';
		for (int j = 0; j < 26; j++) {
			if (a == j) {
				if (ac[a] >= cnt2[a]) {
					dp[i][a] = cnt2[a];
					cnt2[a]++;
				}
				
			}
			else
				dp[i][j] = dp[i - 1][j];
		}
	}


	while (q--) {
		char a;
		cin >> a;
		a -= 'a';
		int l, r;
		cin >> l >> r;
		if (l == 0)
			cout << dp[r + 1][a] << '\n';
		else
			cout << dp[r + 1][a] - dp[l][a] << '\n';
	}

}
