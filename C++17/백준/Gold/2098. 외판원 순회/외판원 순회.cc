#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int W[16][16];
int INF = 1000000 * 16 + 1;
int N;
int D[16][1 << 16];
int tsp(int c, int v);

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			cin >> W[i][j];
	}
	cout << tsp(0, 1);
}

int tsp(int c, int v) {

	if (v == (1 << N) - 1)
		return W[c][0] == 0 ? INF : W[c][0];

	if (D[c][v] != 0)
		return D[c][v];
	int min_val = INF;
	for (int i = 0; i < N; i++) {
		if ((v & (1 << i)) == 0 && W[c][i] != 0) {
			min_val = min(min_val, tsp(i, (v | (1 << i))) + W[c][i]);
		}

	}
	D[c][v] = min_val;
	return D[c][v];
}