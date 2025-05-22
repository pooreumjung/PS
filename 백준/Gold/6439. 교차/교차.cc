#include<iostream>
#include<vector>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;
ll tc, a, b, c, d, ix1, iy1, ix2, iy2;

ll ccw(P, P, P);
bool func(P p1, P p2, P p3, P p4) {
	ll ccw1 = ccw(p1, p2, p3);
	ll ccw2 = ccw(p1, p2, p4);
	ll ccw3 = ccw(p3, p4, p1);
	ll ccw4 = ccw(p3, p4, p2);

	if (ccw1 == 0 && ccw2 == 0 && ccw3 == 0 && ccw4 == 0) {
		if (min(p1.first, p2.first) > max(p3.first, p3.first) ||
			min(p1.second, p2.second) > max(p3.second, p4.second) ||
			min(p3.first, p3.first) > max(p1.first, p2.first) ||
			min(p3.second, p4.second) > max(p1.second, p2.second)) return false;
	}
	if (ccw1 * ccw2 <= 0 && ccw3 * ccw4 <= 0) return true;
	return false;
}
ll ccw(P p1, P p2, P p3) {
	return p1.first * p2.second + p2.first * p3.second + p3.first * p1.second - (p1.first * p3.second + p3.first * p2.second + p2.first * p1.second);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> tc;
	while (tc--) {
		cin >> ix1 >> iy1 >> ix2 >> iy2 >> a >> b >> c >> d;
		P i1 = make_pair(ix1, iy1);
		P i2 = make_pair(ix2, iy2);
		ll minx = min(a, c);
		ll miny = min(b, d);
		ll maxx = max(a, c);
		ll maxy = max(b, d);
		ll minix = min(ix1, ix2);
		ll miniy = min(iy1, iy2);
		ll maxix = max(ix1, ix2);
		ll maxiy = max(iy1, iy2);
		if (func({ a,b }, { a,d }, i1, i2)) {
			cout << "T\n";
			continue;
		}
		if (func({ a,b }, { c,b }, i1, i2)) {
			cout << "T\n";
			continue;
		}
		if (func({ c,d }, { c,b }, i1, i2)) {
			cout << "T\n";
			continue;
		}
		if (func({ a,d }, { c,d }, i1, i2)) {
			cout << "T\n";
			continue;
		}
		if (minx <= minix && maxix <= maxx && miny <= miniy && miniy <= maxy) {
			cout << "T\n";
			continue;
		}
		cout << "F\n";
	}
	return 0;
}

