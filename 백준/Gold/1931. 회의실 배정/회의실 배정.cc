#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> v;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, start, end;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> start >> end;
        v.push_back(make_pair(end, start));
    }

    // 각각 시작시간과 끝나는 시간에 대해서 오름차순 정렬
    sort(v.begin(), v.end());

    // 최소로 빨리 끝나는 시간 설정
    int minEnd = v[0].first, count = 1;
    for (int i = 1; i < n; i++)
    {
        if (v[i].second >= minEnd)
        {
            minEnd = v[i].first;
            count++;
        }
    }

    cout << count;
}