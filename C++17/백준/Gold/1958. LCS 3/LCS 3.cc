#include<iostream>
#include<string>
#include<cmath>
using namespace std;

int map[101][101][101];
int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string A, B, C;
	cin >> A >> B >> C;

	int len1 = A.size();
	int len2 = B.size();
	int len3 = C.size();

	for (int i = 1; i <= len1; i++) {
		for (int j = 1; j <= len2; j++) {
			for (int k = 1; k <= len3; k++) {
				if (A[i - 1] == B[j - 1]&&B[j-1] == C[k - 1])
					map[i][j][k] = map[i - 1][j - 1][k - 1] + 1;
				else
					map[i][j][k] = max(max(map[i - 1][j][k], map[i][j - 1][k]),map[i][j][k-1]);
			}
		}
	}
	cout << map[A.size()][B.size()][C.size()];
}