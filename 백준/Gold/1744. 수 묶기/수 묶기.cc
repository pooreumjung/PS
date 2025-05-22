#include<iostream>
#include<queue>
using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N,data;
	cin >> N;

	priority_queue<int>pluspq;
	priority_queue<int, vector<int>, greater<int>>minuspq;

	int zero = 0, one = 0;
	for (int i = 0; i < N; i++) {
		cin >> data;
		if (data > 1)
			pluspq.push(data);
		else if (data == 1)
			one++;
		else if (data == 0)
			zero++;
		else
			minuspq.push(data);
	}
	int sum = 0;

	while (pluspq.size() > 1) {
		int first = pluspq.top();
		pluspq.pop();
		int second = pluspq.top();
		pluspq.pop();
		sum += (first * second);
	}
	if (!pluspq.empty()) {
		sum += pluspq.top();
		pluspq.pop();
	}

	while (minuspq.size() > 1) {
		int first = minuspq.top();
		minuspq.pop();
		int second = minuspq.top();
		minuspq.pop();
		sum += (first * second);
	}
	if (!minuspq.empty()) {
		if (zero == 0) {
			sum += minuspq.top();
			minuspq.pop();
		}
	}
	sum += one;
	cout << sum;
}