#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[101];
vector<pair<int, int>> v;

bool compare(const pair<int, int> &v1, const pair<int, int> &v2)
{
    if (v1.first == v2.first)
        return v1.second < v2.second;
    return v1.first < v2.first;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }

    sort(v.begin(), v.end(), compare);

    int result = 1;
    for (int i = 0; i < n; i++)
    {
        dp[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (v[j].second < v[i].second)
                dp[i] = max(dp[i], dp[j] + 1);
        }
        result = max(result, dp[i]);
    }

    cout << n - result;
}