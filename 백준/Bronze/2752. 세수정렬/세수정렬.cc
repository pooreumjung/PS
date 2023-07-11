#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int>v(3);
int main() {
	for (int x = 0; x < v.size(); x++)
		cin >> v[x];
	sort(v.begin(), v.end());
	for (int x = 0; x < v.size(); x++)
		cout << v[x] << " ";
}