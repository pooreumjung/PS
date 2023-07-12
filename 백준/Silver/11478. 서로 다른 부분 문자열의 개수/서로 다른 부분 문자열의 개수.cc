#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <string>
#include <set>
using namespace std;
string str,strSearch;
set<string> setSearch;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> str;
	for (int i = 0; i < str.size(); i++) {
		strSearch = "";
		for (int j = i; j < str.size(); j++) {
			strSearch += str[j];
			setSearch.insert(strSearch);
		}
	}
	cout << setSearch.size();
    return 0;
}