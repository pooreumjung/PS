#include<iostream>
#include<stack>
#include<string>
using namespace std;
int find(string a) {
	string finish = " .";
	if (a == finish)
		return 1;
	stack<char>s;
	for (int x = 0; x < a.length(); x++) {
		if (a[x] == '(' || a[x] == '[')
			s.push(a[x]);
		else if (a[x] == ')') {
			if (s.empty() == 1) {
				return 0;
			}
			else if (s.top() == '(')
				s.pop();
			else if (s.top() != '(') {
				return 0;
			}
		}
		else if (a[x] == ']') {
			if (s.empty() == 1) {
				return 0;
			}
			else if (s.top() == '[')
				s.pop();
			else if (s.top() != '[') {
				return 0;
			}
		}
	}
	if (s.empty() == 1)
		return 1;
	else
		return 0;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string finish = " .";
	while (true) {
		string a;
		getline(cin, a);
		if (a == ".")
			break;
		int ab = find(a);
		if (ab == 0)
			cout << "no" << endl;
		else
			cout << "yes" << endl;
	}
}