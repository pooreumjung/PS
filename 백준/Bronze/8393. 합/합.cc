#include<iostream>
using namespace std;
int main() {
	int n,sum=0;
	cin >> n;
	for (int x = 1; x <= n; x++) 
		sum += x;
	cout << sum;


}