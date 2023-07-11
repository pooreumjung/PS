#include<iostream>
#include<string>
#include<stack>
using namespace std;
void print(string input) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string result;
	stack<char>str;
	for (int x = 0; x <= input.length(); x++) {
		if (input[x] == ' ' || x == input.length()) {
			while (!str.empty()) {
				cout << str.top();
				str.pop();
			}
			cout << " ";
		}
		else
			str.push(input[x]);
	}
	cout << endl;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int num;
	cin >> num;
	cin.ignore();
	for (int x = 0; x < num; x++) {
		string input;
		getline(cin, input);
		print(input);
	}
}