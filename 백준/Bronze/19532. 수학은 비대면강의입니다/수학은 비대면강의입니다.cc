#include <iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int a, b, c, d, e, f;
	int x = 0;
	int y = 0;
	cin >> a >> b >> c >> d >> e >> f;
	for ( x = -999; x <= 999; x++)
	{
		for ( y = -999; y <= 999; y++)
		{
			if ((((a* x) + (b * y) == c))&&(d * x + e * y == f))
			{
					break;
			}

		}
		if ((((a * x) + (b * y) == c)) && (d * x + e * y == f))
		{
			break;
		}
	}
	cout << x<<" " << y;
}