#include<iostream>
#include<string>
using namespace std;
int count1;
string str[9] = { "ABC","DEF","GHI","JKL","MNO","PQRS","TUV","WXYZ" };
int find(char a) {
	int index = 0;
	for (int x = 0; x < 9; x++) {
		if (str[x].find(a)!=-1) {
			index = x;
			break;
		}

	}
	return index + 3;

}
int main() {
	string input;
	cin >> input;
	for (int x = 0; x < input.size(); x++) {
		int a = find(input[x]);
		count1 += a;
	}
	cout << count1;
}