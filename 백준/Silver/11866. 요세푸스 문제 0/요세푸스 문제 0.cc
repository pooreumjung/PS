#include<iostream>
#include<queue>
using namespace std;
int main() {

	int n, k;
	cin >> n >> k;
	queue<int>q;
	for (int x = 1; x <= n; x++)
		q.push(x);
	cout << "<";
	while (q.size() - 1) {
		for (int x = 0; x < k - 1; x++) {
			q.push(q.front());
			q.pop();
		}
		cout << q.front() << ", ";
		q.pop();
	}
	cout << q.front() << ">";
}