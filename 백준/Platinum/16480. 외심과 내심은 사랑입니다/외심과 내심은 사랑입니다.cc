#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long R, r;
    cin >> R >> r;

    long long result = pow(R, 2) - 2 * R * r;
    cout << result;
}