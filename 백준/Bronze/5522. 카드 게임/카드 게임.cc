#include<iostream>
using namespace std;
int main() {
	int n=5,m,sum=0;
	for (int x = 0; x < n; x++) {
		cin >> m;
		sum += m;
	}
	cout << sum;
}