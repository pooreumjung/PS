#include<iostream>
#include<stack>
#include<string>
using namespace std;
int find(string a) {
	stack<char>s;
	for (int x = 0; x < a.length(); x++) {
		if (a[x] == '(')
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
	int n;
	cin >> n;
	for (int x = 0; x < n; x++) {
		string input;
		cin >> input;
		int a=find(input);
		if (a == 0)
			cout << "NO" << endl;
		else
			cout << "YES" << endl;
	}
}