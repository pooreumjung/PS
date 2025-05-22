#include<iostream>
#include<stack>
using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	stack<int>myStack;

	for (int i = 0; i < N; i++) {
		
		int order;
		cin >> order;

		if (order == 1) {
			int x;
			cin >> x;
			myStack.push(x);
		}
		
		else if (order == 2) {
			if (myStack.size() != 0) {
				int a = myStack.top();
				cout << a<<'\n';
				myStack.pop();
			}
			else
				cout << -1 << '\n';
		}
		else if (order == 3) {
			cout << myStack.size()<<"\n";
		}
		else if (order == 4) {
			if (myStack.size() == 0)
				cout << 1 << "\n";
			else
				cout << 0 << '\n';
		}
		else if (order == 5) {
			if (myStack.size() == 0)
				cout << -1 << '\n';
			else
				cout << myStack.top()<<'\n';
		}
	}

}