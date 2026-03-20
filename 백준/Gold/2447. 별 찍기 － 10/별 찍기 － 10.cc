#include <iostream>
using namespace std;

char arr[2200][2200];

void draw(int x, int y, int n)
{
    if (n == 1)
    {
        arr[x][y] = '*';
        return;
    }

    int size = n / 3;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (i == 1 && j == 1)
                continue; // 가운데 비우기
            draw(x + i * size, y + j * size, size);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            arr[i][j] = ' ';

    draw(0, 0, N);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << arr[i][j];
        }
        cout << '\n';
    }
}