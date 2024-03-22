#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

vector<int>D;
vector<int>L;
vector<int>R;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	D.resize(N);		
	for (int i = 0; i < N; i++)
		cin >> D[i];

	L.resize(N);
	L[0] = D[0];
	int result = L[0];
	for (int i = 1; i < N; i++) {
		L[i] = max(D[i], L[i - 1] + D[i]);
		result = max(result, L[i]);
	}

	R.resize(N);
	R[N - 1] = D[N - 1];
	for (int i =N- 2; i >=0; i--) {
		R[i] = max(D[i], R[i + 1] + D[i]);
	}

	for (int i = 1; i < N-1; i++) {
		int temp = L[i - 1] + R[i + 1];
		result = max(temp, result);
	}
	cout << result;
}