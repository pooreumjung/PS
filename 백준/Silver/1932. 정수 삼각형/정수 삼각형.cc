#include <iostream>
using namespace std;

int cost[501][501];
int dp[501][501];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, index = 1, result = -1;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < index; j++)
            cin >> cost[i][j];
        index++;
    }

    index = 1;
    dp[0][0] = cost[0][0];
    for (int i = 1; i < N; i++)
    {
        dp[i][0] = cost[i][0] + dp[i - 1][0];
        for (int j = 1; j < index; j++)
        {
            dp[i][j] = cost[i][j] + max(dp[i - 1][j - 1], dp[i - 1][j]);
        }
        dp[i][i] = cost[i][i] + dp[i - 1][i - 1];
        index++;
    }

    for (int i = 0; i < N; i++)
        result = max(result, dp[N - 1][i]);

    cout << result;
}