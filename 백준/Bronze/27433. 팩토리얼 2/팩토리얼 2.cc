#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N;
    cin >> N;

    if (N == 1 || N == 0)
        cout << 1;
    else
    {
        for (int i = N - 1; i >= 1; i--)
            N *= i;
        cout << N;
    }
}