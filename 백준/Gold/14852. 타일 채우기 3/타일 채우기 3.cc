#include <iostream>
using namespace std;

#define MAX 1000001
long long int d[MAX][2];

long long int dp(int x)
{
	d[0][0] = 1;
	d[1][0] = 2;
	d[1][1] = 1;

	for (int i = 2; i <= x; ++i)//d[2]~d[x]까지 구함.
	{
		d[i][1] = (d[i - 1][1] + d[i - 1][0]) % 1000000007;
		d[i][0]=(d[i-2][0]+2*d[i][1]) % 1000000007;
	}
	return d[x][0];
}


int main()
{
	int N;
	cin >> N;
	cout << dp(N) << "\n";

	return 0;
}
