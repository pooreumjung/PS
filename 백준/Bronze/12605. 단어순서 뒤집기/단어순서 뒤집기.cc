#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main() {
	int num, cnt = 0;
	string input;
	string word;
	stack<string> str;
	cin >> num;
	cin.ignore();
	for (int i = 0; i < num; i++) {
		cnt = 0;
		getline(cin, input);
		for (int x = 0; x <= input.length(); x++) {
			if (input[x] == ' ' || x == input.length()) {
				cnt++;

				str.push(word);
				word.clear();
			}
			else {
				
				word += input[x];
			}
		}
		cout << "Case #" << i + 1 << ": ";
		for (int x = 0; x < cnt; x++) {
			cout << str.top() << ' ';
			str.pop();
		}
		cout << '\n';
	}
}
