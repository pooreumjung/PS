#include <iostream>
using namespace std;

int dp[10001], arr[10001];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, result = -1;
    cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> arr[i];

    dp[1] = arr[1];
    dp[2] = arr[1] + arr[2];
    dp[3] = max(arr[1] + arr[3], arr[2] + arr[3]);

    for (int i = 4; i <= n; i++)
    {
        int temp = -1, count = 3, index;

        // 연속해서 마시지 않는 경우 우선 탐색
        for (int j = i; j - count >= 0; count++)
            temp = max(dp[i - count] + arr[i - 1], temp);

        dp[i] = max(dp[i - 2] + arr[i], temp + arr[i]);
    }

    for (int i = 1; i <= n; i++)
        result = max(result, dp[i]);
    cout << result;
}