#include <iostream>
using namespace std;

char arr[2001][2001], ex1[2001][2001], ex2[2001][2001];
int cost1[2001][2001], cost2[2001][2001];
void init(int n, int m, char startC)
{
    char temp = 'B';
    ex1[1][1] = temp;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (i == 1 && j == 1)
                continue;
            if (j == 1)
            {
                if (ex1[i - 1][j] == 'B')
                {
                    ex1[i][j] = 'W';
                    temp = 'W';
                }
                else
                {
                    ex1[i][j] = 'B';
                    temp = 'B';
                }
            }
            else
            {
                if (temp == 'B')
                {
                    ex1[i][j] = 'W';
                    temp = 'W';
                }
                else
                {
                    ex1[i][j] = 'B';
                    temp = 'B';
                }
            }
        }
    }

    temp = 'W';
    ex2[1][1] = temp;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (i == 1 && j == 1)
                continue;
            if (j == 1)
            {
                if (ex2[i - 1][j] == 'B')
                {
                    ex2[i][j] = 'W';
                    temp = 'W';
                }
                else
                {
                    ex2[i][j] = 'B';
                    temp = 'B';
                }
            }
            else
            {
                if (temp == 'B')
                {
                    ex2[i][j] = 'W';
                    temp = 'W';
                }
                else
                {
                    ex2[i][j] = 'B';
                    temp = 'B';
                }
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;

    // 입력받기
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            cin >> arr[i][j];
    }

    // 배열 전처리
    init(n, m, arr[1][1]);

    // 비교해서 누적합 처리
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            int temp1, temp2;
            if (arr[i][j] != ex1[i][j])
                temp1 = 1;
            else
                temp1 = 0;
            if (arr[i][j] != ex2[i][j])
                temp2 = 1;
            else
                temp2 = 0;
            if (j == 1)
            {
                cost1[i][j] = temp1 + cost1[i - 1][j];
                cost2[i][j] = temp2 + cost2[i - 1][j];
            }
            else if (i == 1)
            {
                cost1[i][j] = temp1 + cost1[i][j - 1];
                cost2[i][j] = temp2 + cost2[i][j - 1];
            }
            else
            {
                cost1[i][j] = temp1 + cost1[i - 1][j] + cost1[i][j - 1] - cost1[i - 1][j - 1];
                cost2[i][j] = temp2 + cost2[i - 1][j] + cost2[i][j - 1] - cost2[i - 1][j - 1];
            }
        }
    }

    // 최솟값 찾기
    int result = 80000000;
    for (int i = 1; i <= n - k + 1; i++)
    {
        for (int j = 1; j <= m - k + 1; j++)
        {
            int x1 = i, y1 = j;
            int x2 = i + k - 1, y2 = j + k - 1;
            int temp1 = cost1[x2][y2] - cost1[x2][y1 - 1] - cost1[x1 - 1][y2] + cost1[x1 - 1][y1 - 1];
            int temp2 = cost2[x2][y2] - cost2[x2][y1 - 1] - cost2[x1 - 1][y2] + cost2[x1 - 1][y1 - 1];
            result = min(min(temp1, temp2), result);
        }
    }

    cout << result;
}