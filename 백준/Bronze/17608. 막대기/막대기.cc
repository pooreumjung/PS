#include<iostream>
#include<stack>
using namespace std;
int main() {
	int n;
	cin >> n;
	stack<int>s;
	for (int x = 0; x < n; x++) {
		int num;
		cin >> num;
		s.push(num);
	}
	int count = 0;
	int max = s.top();
	s.pop();
	while (!s.empty()) {
		if (s.top() > max) {
			count++;
			max = s.top();
		}
		s.pop();
	}
	cout << count + 1;
}