#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int N, result = 100000;
int arr[21][21];
bool visited[21];
pair<int, int> calculate()
{
    pair<int, int> temp = make_pair(0, 0);
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (visited[i] && visited[j])
                temp.first += arr[i][j];
            else if (!visited[i] && !visited[j])
                temp.second += arr[i][j];
        }
    }

    return temp;
}
void func(int depth, int start)
{
    // 2팀으로 나눠진 경우
    if (depth == N / 2)
    {
        pair<int, int> total = calculate();
        result = min(result, abs(total.first - total.second));
        return;
    }

    for (int i = start; i <= N; i++)
    {
        visited[i] = true;
        func(depth + 1, i + 1);
        visited[i] = false;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            cin >> arr[i][j];

    func(0, 1);
    cout << result;
}