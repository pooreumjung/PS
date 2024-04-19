#include<iostream>
#include<tuple>
#include<vector>
using namespace std;

#define ll long long
typedef tuple<ll ,ll ,ll>cur;
vector<cur>res;

long gcd(int a, int b);
int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll a, b;
	cin >> a >> b;
	ll mul = a * b;

	for (ll i = a; i <= b; i+=a) {
		if (mul % i == 0) {			
			if (gcd(i, (mul / i)) == a) {
				res.push_back(cur{ i,mul / i,i + (mul / i) });
			}
		}
	}

	int index = 0;
	int min = 300000000;
	for (int i = 0; i < res.size(); i++) {
		cur temp = res[i];
		int value = get<2>(temp);
		if (min > value) {
			index = i;
			min = value;
		}
	}

	cur result = res[index];
	cout << get<0>(result) << " " << get<1>(result);
}
long gcd(int a, int b) {
	if (b == 0)
		return a;
	else
		return gcd(b, a % b);
}
