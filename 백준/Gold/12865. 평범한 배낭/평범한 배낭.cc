#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> arr;
int dp[100001]; // 각 무게에서의 최대 가치
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k, result = -1;
    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        int w, v;
        cin >> w >> v;
        arr.push_back(make_pair(w, v));
    }

    sort(arr.begin(), arr.end());

    for (int i = 0; i < n; i++)
    {
        pair<int, int> cur = arr[i];
        int weight = cur.first;
        int value = cur.second;

        for (int j = k; j >= weight; j--)
            dp[j] = max(dp[j], dp[j - weight] + value);
    }

    cout << dp[k];
}