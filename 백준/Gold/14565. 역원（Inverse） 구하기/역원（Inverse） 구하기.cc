#include<iostream>
using namespace std;
#define ll long long

ll exEuclid(ll a, ll b, ll &s, ll &t) {
	if (b == 0) {
		s = 1; t = 0;
		return a;
	}
	ll gcd = exEuclid(b, a%b, s, t);
	ll temp = t;
	t = s - (a / b)*t;
	s = temp;

	if (s <= 0) {
		s += b;
		t -= a;
	}
	return gcd;
}

int main(void) {
	ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    
	ll n, a; 
    cin >> n >> a;
	
    ll c, k;
	ll g = exEuclid(a, n, c, k);
    
	if (g != 1) 
        cout << n - a << ' ' << -1;
	else
        cout << n - a << ' ' << c;
}