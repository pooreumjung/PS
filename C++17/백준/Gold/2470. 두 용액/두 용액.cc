#include<iostream>
#include<vector>
#include<algorithm>

int idx1;
int idx2;
long Min = 2000000000;

using namespace std;
int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	vector<long>A(N, 0);
	for (int i = 0; i < N; i++)
		cin >> A[i];

	sort(A.begin(), A.end());
	if (A[0] >= 0) {
		cout << A[0] << " " << A[1];
		return 0;
	}
	if (A[N - 1] < 0) {
		cout << A[N - 2] << " " << A[N - 1];
		return 0;
	}
		int i = 0;
		int j = N - 1;
		while (i <= j) {
			if (A[i] + A[j] == 0) {
				idx1 = i;
				idx2 = j;
				break;
			}
			else if (A[i] + A[j] > 0) {
				if (A[i] + A[j] < Min) {
					Min = A[i] + A[j];
					idx1 = i;
					idx2 = j;
				}
				j--;
			}
			else if (A[i] + A[j] < 0) {
				if (abs(A[i] + A[j]) < Min) {
					Min = abs(A[i] + A[j]);
					idx1 = i;
					idx2 = j;
				}
				i++;
			}
			if (i == j)
				j--;
		}
		cout << A[idx1] << " " << A[idx2];
	}
	
