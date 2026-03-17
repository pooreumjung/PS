#include <iostream>
#include <queue>
using namespace std;

int jumpCount[301][301];
char arr[301][301];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
queue<pair<int, int>> q;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, x1, y1, x2, y2;
    cin >> N >> M >> x1 >> y1 >> x2 >> y2;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            cin >> arr[i][j];
            jumpCount[i][j] = 9999;
        }
    }

    arr[x1][y1] = '*';
    arr[x2][y2] = '#';

    q.push(make_pair(x1, y1));
    jumpCount[x1][y1] = 0;

    while (!q.empty())
    {
        pair<int, int> cur = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int mx = cur.first + dx[i];
            int my = cur.second + dy[i];

            if (mx < 1 || my < 1 || mx > N || my > M)
                continue;

            int nextCost = jumpCount[cur.first][cur.second];
            if (arr[mx][my] == '1')
                nextCost++;

            if (nextCost < jumpCount[mx][my])
            {
                jumpCount[mx][my] = nextCost;
                q.push(make_pair(mx, my));
            }
        }
    }

    cout << jumpCount[x2][y2] + 1;
}