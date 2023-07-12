#include<iostream>
#include<map>
#include<string>
#include<vector>
using namespace std;
int main() {
	map<string, int>mp;
	vector < string > p;
	int n, m;
	string input;
	cin >> n >> m;
	for (int x = 0; x < n + m; x++) {
		cin >> input;
		mp[input]++;
	}
	for (auto iter = mp.begin(); iter != mp.end(); iter++) {
		if (iter->second > 1)
			p.push_back(iter->first);
	}
	cout << p.size() << endl;
	for (int x = 0; x < p.size(); x++)
		cout << p[x] << endl;
}