#include <map>
#include <iostream>
using namespace std;
const int MOD = 1000000007;
long long N;
map<long long, long long> fibonacciDP;

long long fibonacci(long long cnt);

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N;

	cout << fibonacci(N) << '\n';

	return 0;
}

long long fibonacci(long long cnt)
{
	if (cnt == 0) return 0;
	else if (cnt == 1) return 1;
	else if (cnt == 2) return 1;
	else if (fibonacciDP.find(cnt) != fibonacciDP.end()) return fibonacciDP[cnt];

	long long n, fn, fnPlus, fnMinus;
	if (cnt % 2)
	{
		// f(2n+1) = f(n+1) * f(n+1) + f(n) * f(n) // 홀수 식
		n = (cnt - 1) / 2;
		fnPlus = fibonacci(n + 1);
		fn = fibonacci(n);

		return (fibonacciDP[cnt] = ( (fnPlus * fnPlus) % MOD + (fn * fn) % MOD) % MOD );
	}
	else
	{
		// f (2n) = f(n) * (f(n) + 2 * f(n-1))  // 짝수 식
		n = cnt / 2;
		fnMinus = fibonacci(n - 1);
		fn = fibonacci(n);

		return (fibonacciDP[cnt] = (fn * ((fn + 2 * fnMinus) % MOD)) % MOD );
	}
}