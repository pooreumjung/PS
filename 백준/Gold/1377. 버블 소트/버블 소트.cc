#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	vector<pair<int,int>>A(N);

	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;
		A[i].first = x; 
		A[i].second = i; 
	}

	sort(A.begin(), A.end()); 
	int max = 0;

	for (int i = 0; i < N; i++) {
		int temp = A[i].second - i;
		if (max < temp)
			max = temp;
	}

	cout << max + 1;
}