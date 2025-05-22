#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

#define MAX 99999999.999999
double W[16][16];
double D[16][1 << 16];
int N;
typedef pair<int, int>cur;
cur arr[16];
double tsp(int start, int visit);
int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> arr[i].first >> arr[i].second;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i == j)
				continue;
			if (W[i][j])
				continue;
			else {
				int a = arr[j].second - arr[i].second;
				int b = arr[j].first - arr[i].first;
				W[i][j] = sqrt(a * a + b * b);
			}
		}
	}

	double result = tsp(0, 1);
	cout << fixed;
	cout << result;
}
double tsp(int start, int visit) {
	if (visit == ((1 << N) - 1))
		return W[start][0];

	if (D[start][visit])
		return D[start][visit];

	double min_val = MAX;
	for (int i = 1; i < N; i++) {
		if ((visit & (1 << i)) == 0&&W[start][i]!=0)
			min_val = min(min_val, tsp(i, visit | (1 << i)) + W[start][i]);
	}
	D[start][visit] = min_val;
	return D[start][visit];
}