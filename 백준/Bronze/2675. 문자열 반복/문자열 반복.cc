#include<iostream>
#include<string>
#include<cstring>
using namespace std;
int main() {
	int T;
	cin >> T;
	for (int x = 0; x < T; x++) {
		int n;
		cin >> n;
		string str;
		cin >> str;
		int len = str.length();
		for (int x = 0; x < len; x++) {
			string arr;
			for (int y = 0; y < n; y++)
				arr += str[x];
			cout << arr;
		}
		cout << "\n";
	}


}