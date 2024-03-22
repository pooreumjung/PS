#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

vector<int>T;
vector<int>P;
vector<int>D;
int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	T.resize(N + 1);
	P.resize(N + 1);
	D.resize(N + 2);

	for (int i = 1; i <= N; i++) {
		cin >> T[i] >> P[i];
	}

	for (int i = N; i > 0; i--) {
		if (i + T[i] > N + 1)
			D[i] = D[i + 1];
		else
			D[i] = max(D[i + 1], D[i + T[i]] + P[i]);
	}
	cout << D[1];
}