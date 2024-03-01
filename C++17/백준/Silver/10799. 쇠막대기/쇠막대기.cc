#include<iostream>
#include<stack>
#include<vector>
using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string A;
	cin >> A;
	stack<char>myStack;

	int new_Bar = 0;
	int result = 0;

	for (int i = 0; i < A.length(); i++) {
		
		if (A[i] == '(') {
			myStack.push('c');		
		}

		if (A[i] == ')') {

			if (i >= 1 && A[i - 1] == '(') {
				myStack.pop();
				result += myStack.size();
			}

			else {
				new_Bar++;
				myStack.pop();
			}
		}
	}
	result += new_Bar;
	cout << result;
}