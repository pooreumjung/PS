#include<iostream>
#include<cmath>
using namespace std;

int CCW(long x1, long y1, long x2, long y2, long x3, long y3);
bool isCross(long x1, long y1, long x2, long y2, long x3, long y3, long x4, long y4);
int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long x1, y1, x2, y2, x3, y3, x4, y4;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

	bool check = isCross(x1, y1, x2, y2, x3, y3, x4, y4);
	if (check)
		cout << 1;
	else
		cout << 0;
}
bool isCross(long x1, long y1, long x2, long y2, long x3, long y3, long x4, long y4) {
	int abc = CCW(x1, y1, x2, y2, x3, y3);
	int abd = CCW(x1, y1, x2, y2, x4, y4);
	int cda = CCW(x3, y3, x4, y4, x1, y1);
	int cdb = CCW(x3, y3, x4, y4, x2, y2);

	if (abc * abd < 0 && cda * cdb < 0)
		return true;
	else
		return false;
}
int CCW(long x1, long y1, long x2, long y2, long x3, long y3) {
	long result = (x1 * y2 + x2 * y3 + x3 * y1) - (y1 * x2 + y2 * x3 + y3 * x1);
	if (result < 0)
		return -1;
	else if (result > 0)
		return 1;
	else
		return 0;
}
/*

두 선분이 교차한다
=> abc*abd <0 이고 cda*cdb<0이면 된다
두 선분이 겹치면 안 됨
*/