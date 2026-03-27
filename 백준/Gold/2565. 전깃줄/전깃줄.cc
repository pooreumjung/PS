#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[501];
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

    int n, result = 1;
    cin >> n;

    // 입력 받기
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        v.push_back(make_pair(a, b));
    }

    // a좌표, b좌표 순으로 정렬
    sort(v.begin(), v.end(), compare);

    // 탐색 시작
    for (int i = 0; i < n; i++)
    {
        dp[i] = 1;
        pair<int, int> cur = v[i];
        // 현재보다 앞의 인덱스로 가면서 겹치는 것들 탐색
        for (int j = i - 1; j >= 0; j--)
        {
            // 그다음 출발점과 탐색점
            pair<int, int> next = v[j];
            if (cur.second > next.second)
                dp[i] = max(dp[j] + 1, dp[i]);
        }
        result = max(result, dp[i]);
    }

    cout << n - result;
}
