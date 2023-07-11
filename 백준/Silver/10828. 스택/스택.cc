#include<iostream>
#include<string>
#include<stack>
using namespace std;
int main() {
	int num;
	stack<int>s;
	cin >> num;
	for (int x = 0; x < num; x++) {
		string input;
		cin >> input;
		if (input == "pop") {
			if (s.empty() == true)
				cout << -1 << endl;
			else {
				cout << s.top() << endl;
				s.pop();
			}
		}
		else if (input == "top") {
			if (s.empty() == true)
				cout << -1 << endl;
			else {
				cout << s.top() << endl;
			}
		}
		else if (input == "size")
			cout << s.size() << endl;
		else if (input == "empty")
			cout << s.empty() << endl;
		else {
			int n;
			cin >> n;
			s.push(n);
		}
	}
}