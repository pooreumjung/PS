#include<iostream>
#include<stack>
using namespace std;
int main() {
	stack<int>s;
	int k;
	cin >> k;
	for (int x = 0; x < k; x++) {
		int n;
		cin >> n;
		if (n == 0)
			s.pop();
		else
			s.push(n);
	}
	int sum = 0;
	while(s.empty()!=1){

		sum += s.top();
		s.pop();
	}
	cout << sum;
}