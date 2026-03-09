#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(long long num)
{
    if (num < 2)
        return false;
    else if (num == 2)
        return true;
    if (num % 2 == 0)
        return false;

    for (long long i = 3; i <= sqrt(num); i += 2)
        if (num % i == 0)
            return false;
    return true;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    long long num;
    while (N--)
    {
        cin >> num;
        while (!isPrime(num))
            num++;
        cout << num << '\n';
    }
}