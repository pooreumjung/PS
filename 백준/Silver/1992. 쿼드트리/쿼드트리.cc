#include <iostream>
using namespace std;

char arr[65][65];
void solve(int x, int y, int size)
{
    char temp = arr[x][y];
    bool isSame = true;

    // 같은지 탐색
    for (int i = x; i < x + size; i++)
    {
        for (int j = y; j < y + size; j++)
        {
            if (temp != arr[i][j])
            {
                isSame = false;
                break;
            }
        }
        if (!isSame)
            break;
    }

    // 같은 경우
    if (isSame)
    {
        cout << temp;
        return;
    }

    int half = size / 2;
    cout << "(";
    solve(x, y, half);
    solve(x, y + half, half);
    solve(x + half, y, half);
    solve(x + half, y + half, half);
    cout << ")";
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
            cin >> arr[i][j];
    }

    solve(1, 1, N);
}