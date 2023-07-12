#include <iostream>
using namespace std;

bool ck[1010101] = { false }; 

int main(void)
{
	long long i, j, n, x, ans=1;
	for (i = 2; i <= 1000000; i++)
	{
		if (ck[i])continue;
		for (j = i * 2; j <= 1000000; j += i) ck[j] = true;
	}
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> x;
		if (!ck[x] && ans%x) ans *= x; 
	}
	if (ans == 1) cout << -1;
	else cout << ans;
}