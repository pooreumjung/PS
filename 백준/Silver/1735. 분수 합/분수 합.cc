#include <iostream>
#include <string>
using namespace std;
int GCD(int, int);
int main()
{
	int numerator, denominator;
	int numerator1, denominator1;
	int numerator2, denominator2;
	int gcd;

	cin >> numerator1 >> denominator1;
	cin >> numerator2 >> denominator2;

	if (denominator1 == denominator2)
	{
		numerator = numerator1 + numerator2;
		denominator = denominator1;
	}
	else
	{
		numerator = (numerator1 * denominator2) + (numerator2 * denominator1);
		denominator = denominator1 * denominator2;
	}

		gcd = GCD(denominator, numerator);
		cout << numerator / gcd <<" "<< denominator / gcd << endl;

	return 0;
}
int GCD(int B, int A)
{
	if (B % A == 0)
		return A;
	else
		return GCD(A, B%A);
}