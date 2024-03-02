#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int idx1;
int idx2;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	int count = 0;
	long dif = 2000000000;

	vector<long>A(N, 0);

	for (int i = 0; i < N; i++)
		cin >> A[i];

	sort(A.begin(), A.end());


	int i = 0;
	int j = N - 1;

	while (i <= j) {
		if (A[i] + A[j] == 0) {
			idx1 = i;
			idx2 = j;
			break;
		}

		else if (A[i] + A[j] < 0) {
			if (abs(A[i]+A[j]) < dif) {
				idx1 = i;
				idx2 = j;
				dif = abs(A[i] + A[j]);
			}
			i++;
		}

		else if (A[i] + A[j] > 0) { // 두 개의 합이 양수일 때			
			if (A[i] +A[j]< dif) {
				idx1 = i;
				idx2 = j;
				dif = A[i] + A[j];
			}
			j--;
		}
		if (i == j)
			j--;
	}

	cout << A[idx1] << " " << A[idx2];

}