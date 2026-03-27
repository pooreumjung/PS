#include <iostream>
#include <algorithm>
using namespace std;

int arr[1001], dp[1001], dp2[1001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> arr[i];

    // 가장 긴 증가하는 부분 수열의 길이 구하기
    for (int i = 1; i <= n; i++)
    {
        dp[i] = 1;
        for (int j = 1; j < i; j++)
        {
            if (arr[i] > arr[j])
                dp[i] = max(dp[i], dp[j] + 1);
        }
    }

    // 가장 긴 감소하는 부분 수열의 길이 구하기
    for (int i = n; i >= 1; i--)
    {
        dp2[i] = 1;
        for (int j = i + 1; j <= n; j++)
        {
            if (arr[i] > arr[j])
                dp2[i] = max(dp2[i], dp2[j] + 1);
        }
    }

    // 결과값 찾기
    int result = 0;
    for (int i = 1; i <= n; i++)
        result = max(result, dp[i] + dp2[i] - 1);

    cout << result;
}