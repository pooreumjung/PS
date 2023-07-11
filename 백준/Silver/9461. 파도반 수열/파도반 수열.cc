#include<iostream>
using namespace std;
unsigned long long p[101] = { 1,1,1,2,2,3,4, };
int t;
unsigned long long find(int a);
int main() {
	cin >> t;
	for (int x = 7; x < 101; x++)
		p[x] = p[x - 2] + p[x - 3];
	for (int x = 0; x < t; x++) {
		int n;
		cin >> n;
		cout << p[n-1] << endl;
	}
}
