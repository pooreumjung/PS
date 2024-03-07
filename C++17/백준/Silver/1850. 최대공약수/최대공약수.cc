#include<iostream>
#include<cmath>
using namespace std;

long gcd(long A, long B);

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	long A, B;
	cin >> A >> B;

	long result = gcd(A, B);
	while (result > 0) {
		cout << 1;
		result--;
	}
	
}

long gcd(long A,long B) {
	if (B == 0)
		return A;
	else {
		return gcd(B, A%B);
	}
}