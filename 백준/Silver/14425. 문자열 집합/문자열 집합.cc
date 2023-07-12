#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M, count = 0;
	string a;
	unordered_map<string, bool> m;
	cin >> N >> M;

	for (int x = 0; x < N;x++) {
		cin >> a;
		m[a] = true;
	}

	for (int x = 0; x < M;x++) {
		cin >> a;
		if (m[a] == true) count++;
	}

	cout << count;

}

