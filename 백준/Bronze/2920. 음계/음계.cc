#include<iostream>
#include<string>
using namespace std;
int main() {
	string str1 = "1 2 3 4 5 6 7 8";
	string str2 = "8 7 6 5 4 3 2 1";
	string str;
	getline(cin, str);
	if(str==str1)
		cout << "ascending";
	else if(str==str2)
		cout << "descending";
	else
		cout << "mixed";
}