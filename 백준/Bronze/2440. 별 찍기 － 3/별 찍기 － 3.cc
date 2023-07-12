#include<iostream>
using namespace std;
void abc(int c) {
	for (int x = 0; x < c; x++)
		cout << "*";
	cout << endl;
}
int main() {
	int n;
	cin >> n;

	for (int x = n; x > 0; x--)
		abc(x);

}