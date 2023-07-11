#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int x = 0;
	int y = 0;
	int w = 0;
	int h = 0;
	cin >> x >> y >> w >> h;
	w -= x;
	h -= y;

	int minimum = x;
	if (minimum > y)
		minimum = y;
	if (minimum > w)
		minimum = w;
	if (minimum > h)
		minimum = h;

	cout << minimum << "\n";
	return 0;
}
