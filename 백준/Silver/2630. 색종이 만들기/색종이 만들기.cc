#include <iostream>
using namespace std;

int arr[129][129];
int whiteCount = 0, blueCount = 0;

void solve(int x, int y, int size)
{
    int color = arr[x][y];
    bool same = true;

    // 현재 영역이 모두 같은 색인지 검사
    for (int i = x; i < x + size; i++)
    {
        for (int j = y; j < y + size; j++)
        {
            if (arr[i][j] != color)
            {
                same = false;
                break;
            }
        }
        if (!same)
            break;
    }

    // 모두 같은 색이면 개수 증가
    if (same)
    {
        if (color == 0)
            whiteCount++;
        else
            blueCount++;
        return;
    }

    // 섞여 있으면 4등분
    int half = size / 2;
    solve(x, y, half);               // 좌상
    solve(x, y + half, half);        // 우상
    solve(x + half, y, half);        // 좌하
    solve(x + half, y + half, half); // 우하
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cin >> arr[i][j];
        }
    }

    solve(1, 1, N);

    cout << whiteCount << "\n"
         << blueCount;
}