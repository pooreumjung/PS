#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<long long> v1, v2;
long long gcd(long long a, long long b)
{
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    long long loc, result = 0;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> loc;
        v1.push_back(loc);
    }

    for (int i = 1; i < N; i++)
        v2.push_back(v1[i] - v1[i - 1]);

    long long g = v2[0];
    for (int i = 1; i < v2.size(); i++)
        g = gcd(g, v2[i]);

    for (int i = 0; i < v2.size(); i++)
        result += v2[i] / g - 1;

    cout << result;
}