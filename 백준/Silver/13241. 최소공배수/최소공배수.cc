#include <iostream>
using namespace std;

long long int gcd(long long int a, long long int b)
{
	long long int c = a % b;

	while (c != 0)
	{
		a = b;
		b = c;
		c = a % b;
	}
	return b;
}

long long int lmc(long long int a, long long int b)
{
	return (a * b) / gcd(a, b);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long int a, b; 

	cin >> a >> b;

	cout << lmc(a, b);
}