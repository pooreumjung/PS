#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
char arr[51][51];
int dp[51][51];
bool visited[51][51];

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int dfs(int x, int y)
{
    if (x < 1 || y < 1 || x > n || y > m || arr[x][y] == 'H')
        return 0;

    if (visited[x][y])
    {
        cout << -1;
        exit(0);
    }

    if (dp[x][y] != 0)
        return dp[x][y];

    visited[x][y] = true;

    int move = arr[x][y] - '0';
    dp[x][y] = 1;

    for (int i = 0; i < 4; i++)
    {
        int nx = x + move * dx[i];
        int ny = y + move * dy[i];

        dp[x][y] = max(dp[x][y], dfs(nx, ny) + 1);
    }

    visited[x][y] = false;

    return dp[x][y];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> arr[i][j];
        }
    }

    cout << dfs(1, 1);
}