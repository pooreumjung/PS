#include<iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	int x;
	if(n==0||n==1)
	cout<<n;
	if(n>=2){
	long long arr[n] = { 0,1 };
	for ( x = 2; x <= n; x++) {
		arr[x] = arr[x - 1] + arr[x - 2];
	}
	cout << arr[n];
	}
}