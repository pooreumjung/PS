#include<iostream>
#include<string>
using namespace std;
void print(int index, string input) {
	input.erase(index - 1, 1);
	cout << input << endl;
}
int main() {
	int num;
	cin >> num;
	for (int x = 0; x < num; x++) {
		getchar();
		int index;
		cin >> index;
		string input;
		cin >> input;
		print(index, input);
	}
}