#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M;
	cin >> N>>M;
	int answer = 0x7fffffff;
	vector<int> v;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		v.push_back(num);
	}
	sort(v.begin(), v.end());
	int idx2 = 0;
	for (int i = 0; i < N; i++) {
		while(idx2<N) {
			if (v[idx2] - v[i] < M)
				idx2++;
			else {
				answer = min(answer, v[idx2] - v[i]);
				break;
			}
		}
	}

	cout << answer << "\n";

	return 0;
}
