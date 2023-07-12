#include <iostream>
#include<list>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string input;
	cin >> input;
	int n;
	cin >> n;
	list<char>l;
	for (auto c : input)
		l.push_back(c);
	list<char>::iterator t = l.end();
	for (int x = 0; x < n; x++) {
		char op;
		cin >> op;
		if (op == 'L') {
			if (t != l.begin())
				t--;
		}
		else if (op == 'D') {
			if(t!=l.end())
				t++;
		}
		else if (op == 'B') {
			if (t != l.begin()) {
				t--;
				t = l.erase(t);
			}
		}
		else if (op == 'P') {
			char a;
			cin >> a;
			l.insert(t, a);
		}

	}
	for (list<char>::iterator it = l.begin(); it != l.end(); it++)
		cout << *it;

}