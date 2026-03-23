#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, num;
long minResult = 9999999999, maxResult = -999999999;
vector<int> v;
int arr[4];
// 계산하기
long calculate(long num1, long num2, int op)
{
    long temp = 0;
    switch (op)
    {
    case 0:
        temp = num1 + num2;
        break;
    case 1:
        temp = num1 - num2;
        break;
    case 2:
        temp = num1 * num2;
        break;
    case 3:
        temp = num1 / num2;
        break;
    default:
        break;
    }

    return temp;
}
void dfs(int depth, long state)
{
    if (depth == N)
    {
        minResult = min(minResult, state);
        maxResult = max(maxResult, state);
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        if (arr[i])
        {
            arr[i]--;
            dfs(depth + 1, calculate(state, v[depth], i));
            arr[i]++;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> num;
        v.push_back(num);
    }

    for (int i = 0; i < 4; i++)
        cin >> arr[i];

    dfs(1, v[0]);
    cout << maxResult << '\n'
         << minResult;
}