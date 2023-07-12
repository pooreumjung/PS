#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

bool compare(pair <int,int> p1, pair <int, int> p2) {
	if (p1.first == p2.first) return p1.second < p2.second; 
	return p1.first < p2.first;
}

int main() {
	int t;
	vector<pair<int, int>> vec;
	cin >> t;
	while(t--) {
		int a, b;
		cin >> a >> b;
		vec.push_back(make_pair(a, b));
	}

	sort(vec.begin(), vec.end(), compare);

	
	for (auto coor: vec) {
		cout << coor.first << " " << coor.second << "\n";
	}
}