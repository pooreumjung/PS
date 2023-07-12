#include <iostream>
#include <vector>
using namespace std;

int pSum[200001] = { 0 };

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;

    cin >> n >> k;

    for (int i = 1; i <= n; i++)
    {
        cin >> pSum[i];
        pSum[i + n] = pSum[i];
    }
    for (int i = 1; i <= 2 * n; i++)
    {
        pSum[i] += pSum[i - 1];
    }

    int ans = 0;
    for (int i = k; i <= 2 * n; i++)
    {
        ans = max(ans, pSum[i] - pSum[i - k]);
    }
    cout << ans;
}
