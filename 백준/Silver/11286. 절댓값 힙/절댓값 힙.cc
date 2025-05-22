#include<iostream>
#include<queue>
#include<vector>
using namespace std;

struct compare {
	bool operator()(int a1, int a2) {

		int first_abs = abs(a1);
		int second_abs = abs(a2);

		if (first_abs == second_abs) // 절댓값이 같다면 음수를 기준으로
			return a1 > a2;
		else // 그게 아니라면 그냥 절댓값을 기준으로
			return first_abs > second_abs;
	}
};

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	priority_queue<int, vector<int>, compare>myQueue;

	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;

		if (x == 0) {
			if (myQueue.empty()) {
				cout << '0' << '\n';
			}
			else {
				cout << myQueue.top() << '\n';
				myQueue.pop();
			}
		}

		else {
			myQueue.push(x);
		}

	}
}