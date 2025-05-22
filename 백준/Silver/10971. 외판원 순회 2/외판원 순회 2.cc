#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

#define MAX 99999999
int W[16][16];
int D[16][1 << 16];
int N;
int tsp(int start, int visit);
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
int tsp(int start, int visit) {
	if (visit == ((1 << N) - 1))
		return W[start][0] == 0 ? MAX : W[start][0];

	if (D[start][visit])
		return D[start][visit];

	int min_val = MAX;
	for (int i = 1; i < N; i++) {
		if ((visit & (1 << i)) == 0 && W[start][i] != 0)
			min_val = min(min_val, tsp(i, visit | (1 << i)) + W[start][i]);
	}
	D[start][visit] = min_val;
	return D[start][visit];
}