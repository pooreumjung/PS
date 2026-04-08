#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, c;
    cin >> n >> c;

    vector<long long> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    sort(v.begin(), v.end());
    long long start = 1, end = v[n - 1], result = 1;

    while (start <= end)
    {
        // 공유기 사이의 거리 구하기
        long long mid = (start + end) / 2;
        long long tempCount = 0, temp;
        long long tempMax = 1000000000000;

        // v2에 각 집들의 좌표 저장
        vector<long long> v2;
        for (int i = 0; i < n; i++)
        {
            if (i == 0)
            {
                temp = v[0];
                tempCount++;
                v2.push_back(v[0]);
                continue;
            }
            if (temp + mid > v[i])
                continue;
            temp = v[i];
            tempCount++;
            v2.push_back(v[i]);
        }

        // c개 이상을 찾은 경우
        if (tempCount >= c)
        {
            // 인접한 집들의 최대 거리 구하기
            for (int i = 1; i < v2.size(); i++)
            {
                long long dif = v2[i] - v2[i - 1];
                tempMax = min(tempMax, dif);
            }
            result = max(result, tempMax);

            start = mid + 1;
        }
        else
            end = mid - 1;
    }

    cout << result;
}
