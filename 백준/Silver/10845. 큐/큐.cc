#include<iostream>
#include<queue>
#include<string>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int num;
	cin >> num;
	queue<int>q;
	for (int x = 0; x < num; x++) {
		string input;
		cin >> input;
		if (input == "push") {
			int number;
			cin >> number;
			q.push(number);
		}
		else if (input == "pop") {
			if (q.empty() == 1)
				cout << -1 << endl;
			else {
				cout << q.front() << endl;
				q.pop();
			}
		}
		else if (input == "size") {
			if (q.empty() == 1)
				cout << 0 << endl;
			else
				cout << q.size()<<endl;
		}
		else if (input == "empty") {
			cout << q.empty() << endl;
		}
		else if (input == "front") {
			if (q.empty() == 1)
				cout << -1 << endl;
			else 
				cout << q.front() << endl;
		}
		else if (input == "back") {
			if (q.empty() == 1)
				cout << -1 << endl;
			else 
				cout << q.back() << endl;
		}
	}
}