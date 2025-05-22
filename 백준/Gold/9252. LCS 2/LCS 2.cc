#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int N;
int dp[1001][1001];
string A, B;
vector<char>path;
void getText(int r, int c);

int main() {

	cin >> A >> B;
	
	for (int i = 1; i <= A.size(); i++) {
		for (int j = 1; j <= B.size(); j++) {
			if (A[i - 1] == B[j - 1])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}
	cout << dp[A.size()][B.size()] << '\n';
	getText(A.size(), B.size());

	for (int i = path.size() - 1; i >= 0; i--)
		cout << path[i];
}
void getText(int r, int c) {
	if (r == 0 || c == 0)
		return;
	if (A[r - 1] == B[c - 1]) {
		path.push_back(A[r - 1]);
		getText(r - 1, c - 1);
	}
	else {
		if (dp[r - 1][c] > dp[r][c - 1])
			getText(r - 1, c);
		else
			getText(r, c - 1);
	}
}