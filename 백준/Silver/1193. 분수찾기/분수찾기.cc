#include <iostream>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int x, rangeMax = 1, cnt = 1;
	cin >> x;

  
	while (x >= rangeMax) {
		rangeMax = rangeMax + cnt++;
	}

    
	if (cnt % 2 == 1) cout << cnt - (rangeMax - x) << '/' << rangeMax - x << '\n';
	else cout << rangeMax - x << '/' << cnt - (rangeMax - x) << '\n';
	

	return 0;
}