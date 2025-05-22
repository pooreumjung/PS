#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int idx1;
int idx2;
int two_pointer();

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		int res = two_pointer();
		cout << res << '\n';
	}
}
int two_pointer() {

	int N, K;
	cin >> N >> K;

	vector<long>A(N, 0);
	vector<pair<long, long>>res;
	long dif = 2000000000;

	for (int i = 0; i < N; i++)
		cin >> A[i];

	sort(A.begin(), A.end());

	int i = 0;
	int j = N - 1;
	bool check = false;

	while (i <= j) {
		if (A[i] + A[j] == K) {			
			if (dif != 0) {
				res.clear();
				res.push_back({ i,j });
				dif = 0;
			}
			else if (dif == 0)
				res.push_back({ i,j });
			i++;
			j--;
			check = true;
		}
		else if (A[i] + A[j] > K) {
			int d = abs(abs(A[i] + A[j]) - abs(K));
			if (check == false) {
				if (d == dif) {
					res.push_back({ i,j });
					dif = d;
				}
				else if (d < dif) {
					res.clear();
					res.push_back({ i,j });
					dif = d;
				}
			}
			j--;
		}
		else if (A[i] + A[j] < K) {
			int d = abs(abs(A[i] + A[j]) - abs(K));
			if (check == false) {
				if (d == dif) {
					dif = d;
					res.push_back({ i,j });
				}
				else if (d < dif) {
					res.clear();
					res.push_back({ i,j });
					dif = d;
				}
			}
			i++;
		}
		if (i == j)
			j--;
	}
	return res.size();
}