#include<iostream>
#include<deque>
#include<string>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int num;
	cin >> num;
	deque<int>q;
	for (int x = 0; x < num; x++) {
		string input;
		cin >> input;
		if (input == "push_front") {
			int number;
			cin >> number;
			q.push_front(number);
		}
		if (input == "push_back") {
			int number;
			cin >> number;
			q.push_back(number);
		}
		else if (input == "pop_front") {
			if (q.empty() == 1)
				cout << -1 << endl;
			else {
				cout << q.front() << endl;
				q.pop_front();
			}
		}
		else if (input == "pop_back") {
			if (q.empty() == 1)
				cout << -1 << endl;
			else {
				cout << q.back() << endl;
				q.pop_back();
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