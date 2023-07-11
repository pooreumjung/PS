#include<iostream>
#include<string>
int find(char a);
using namespace std;
string str;
int main() {
	cin >> str;
	char a = 'a';
	for (int x = 0; x < 26; x++) {
		int len = find(a);
		cout << len << " ";
		a++;
	}

}
int find(char a) {
	int index = str.find(a);
	if (index == -1)
		return -1;
	else
		return index;

}