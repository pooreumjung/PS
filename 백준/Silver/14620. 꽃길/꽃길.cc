#include <iostream>
using namespace std;

bool visited[11][11];
int cost[11][11];
int n, result = 3000000;
int dx[5] = {0, 1, 0, -1, 0};
int dy[5] = {1, 0, -1, 0, 0};

bool canPlant(int x, int y)
{
    for (int k = 0; k < 5; k++)
    {
        int nx = x + dx[k];
        int ny = y + dy[k];
        if (visited[nx][ny])
            return false;
    }
    return true;
}

int getCost(int x, int y)
{
    int sum = 0;
    for (int k = 0; k < 5; k++)
    {
        int nx = x + dx[k];
        int ny = y + dy[k];
        sum += cost[nx][ny];
    }
    return sum;
}

void setFlower(int x, int y, bool state)
{
    for (int k = 0; k < 5; k++)
    {
        int nx = x + dx[k];
        int ny = y + dy[k];
        visited[nx][ny] = state;
    }
}

void solve(int start, int flowerCount, int sum)
{
    if (flowerCount == 3)
    {
        result = min(result, sum);
        return;
    }

    for (int idx = start; idx < (n - 1) * (n - 1); idx++)
    {
        int x = idx / (n - 1) + 1;
        int y = idx % (n - 1) + 1;

        if (x >= n - 1 || y >= n - 1)
            continue;

        if (canPlant(x, y))
        {
            int flowerCost = getCost(x, y);
            setFlower(x, y, true);
            solve(idx + 1, flowerCount + 1, sum + flowerCost);
            setFlower(x, y, false);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> cost[i][j];
    }

    solve(0, 0, 0);
    cout << result;
}