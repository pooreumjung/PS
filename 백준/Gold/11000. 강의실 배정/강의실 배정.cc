#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	vector<pair<int, int>>A(N);

	for (int i = 0; i < N; i++) {
		int x, y;
		cin >> x >> y;
		A.push_back({ x,y });
	}

	sort(A.begin(), A.end());
	
	int pastend, start, end;
	priority_queue<int, vector<int>, greater<int>>time;
	pastend = A[0].second;
	time.push(pastend);

	for (int i = 1; i < A.size(); i++) {
		start = A[i].first;
		end = A[i].second;
		if (time.top() <= start) {
			time.pop();
			time.push(end);
		}
		else {
			time.push(end);
		}
	}
	cout << time.size();
}