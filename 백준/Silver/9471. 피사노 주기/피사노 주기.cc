#include<bits/stdc++.h>
using namespace std;

long long int find_pisano(long long int m) {
    long long a = 1, b = 1;
    long long rate = 0;
    while (true) {
        long long c = (a + b) % m;
        a = b;
        b = c;
        rate ++;
        if (a==1 && b==1)
            return rate;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, n;
    long long int m;
    cin >> t;


    while (t--) {
        cin >> n >> m;
        cout << n << " " << find_pisano(m) << "\n";
    }
}
