#include<iostream>
using namespace std;
int main() {
    long long n, m;
    cin >> n >> m;
    if (n <= m)
        cout << m * (m + 1) / 2 - n * (n - 1) / 2;
    else
        cout << n * (n + 1) / 2 - m * (m - 1) / 2;
}
