#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	unordered_set<int> S;
	int M; cin >> M;

	while (M--) {
		string cmd; int x;
		cin >> cmd;
		if (cmd == "add") {
			cin >> x;
			S.insert(x);
		}
		else if (cmd == "remove") {
			cin >> x;
			S.erase(x);
		}
		else if (cmd == "check") {
			cin >> x;
			if (S.find(x) != S.end()) cout << "1\n";
			else cout << "0\n";
		}
		else if (cmd == "toggle") {
			cin >> x;
			if (S.find(x) != S.end()) S.erase(x);
			else S.insert(x);
		}
		else if (cmd == "all") {
			for (int i = 1; i <= 20; i++) S.insert(i);
		}
		else if (cmd == "empty") {
			S.clear();
		}
	}
	return 0;
}