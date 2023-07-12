#include<iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t;
	while (t--)	{
		int h, w, n; cin >> h >> w >> n;
		int cnt = 1;
		bool flag = false;
		for (int i = 1; i <= w; i++) {
			if (flag) break;
			for (int j = 1; j <= h; j++) {
				if (cnt == n) {
					flag = true;
					if (i < 10)
						cout << j << '0' << i << "\n";
					else
						cout << j << i << "\n";
					break;
				}
				cnt++;
			}
		}
	}
	return 0;
}