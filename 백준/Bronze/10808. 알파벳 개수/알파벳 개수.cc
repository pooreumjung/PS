#include<iostream>
#include<cstring>
#include<algorithm>
int arr[26];
using namespace std;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	char str[101];
	cin >> str;
	for (int x = 0; x < strlen(str); x++) {
		int a = str[x] - 'a';
		arr[a]++;
	}
	for (int x = 0; x < 26; x++)
		cout << arr[x] << " ";
}