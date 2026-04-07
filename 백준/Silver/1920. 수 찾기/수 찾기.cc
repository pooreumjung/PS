#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<long long> v;
int findNum(long long num)
{
    int start = 0, end = v.size() - 1;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (num > v[mid])
        {
            start = mid + 1;
        }
        else if (num < v[mid])
        {
            end = mid - 1;
        }
        else
        {
            return 1;
        }
    }
    return 0;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        long long num;
        cin >> num;
        v.push_back(num);
    }
    sort(v.begin(), v.end());

    cin >> m;
    for (int i = 0; i < m; i++)
    {
        long long temp;
        cin >> temp;
        cout << findNum(temp) << '\n';
    }
}