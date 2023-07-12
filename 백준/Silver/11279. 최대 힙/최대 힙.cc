#include <stdio.h>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int N, x;
	cin >> N;
	priority_queue<int> pQ;
	for (int i = 0; i < N; i++) {
		cin >> x;
		if (x == 0) {
			if (pQ.empty()) cout << "0\n";
			else {
				cout << pQ.top() << "\n";
				pQ.pop();
			}
		}
		else
			pQ.push(x);
	}
	return 0;
}
