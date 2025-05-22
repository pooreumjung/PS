#include<iostream>
using namespace std;

int main() {
	int n;
	cin>> n;
	
	long long a, b, c;
	a = 0;
	b = 1;
	c = 1;
	
	
	for(int i= 0; i<n-2; i++){
		a = b%1000000007;
		b = c%1000000007;
	    c = (a%1000000007 + b%1000000007)%1000000007;
	}

	
	cout<< c <<" "<<n-2;
	return 0;
}