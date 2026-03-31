#include <iostream>
#include <algorithm>
using namespace std;

char arr[2001][2001];
int costB[2001][2001], costW[2001][2001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> arr[i][j];
        }
    }

    // 누적합 만들기
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            char expectedB, expectedW;

            if ((i + j) % 2 == 0)
            {
                expectedB = 'B';
                expectedW = 'W';
            }
            else
            {
                expectedB = 'W';
                expectedW = 'B';
            }

            int diffB = (arr[i][j] != expectedB);
            int diffW = (arr[i][j] != expectedW);

            costB[i][j] = diffB + costB[i - 1][j] + costB[i][j - 1] - costB[i - 1][j - 1];
            costW[i][j] = diffW + costW[i - 1][j] + costW[i][j - 1] - costW[i - 1][j - 1];
        }
    }

    int result = 1e9;

    for (int i = 1; i <= n - k + 1; i++)
    {
        for (int j = 1; j <= m - k + 1; j++)
        {
            int x1 = i, y1 = j;
            int x2 = i + k - 1, y2 = j + k - 1;

            int repaintB = costB[x2][y2] - costB[x1 - 1][y2] - costB[x2][y1 - 1] + costB[x1 - 1][y1 - 1];
            int repaintW = costW[x2][y2] - costW[x1 - 1][y2] - costW[x2][y1 - 1] + costW[x1 - 1][y1 - 1];

            result = min(result, min(repaintB, repaintW));
        }
    }

    cout << result;
}