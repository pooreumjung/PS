#include <iostream>
#include <algorithm>

using namespace std;

int arr[1025][1025];
int func(int x, int y, int size)
{
    if (size == 2)
    {
        int temp[4] = {arr[x][y],
                       arr[x + 1][y],
                       arr[x][y + 1],
                       arr[x + 1][y + 1]};
        sort(temp, temp + 4);
        return temp[2];
    }

    int half = size / 2;
    int a = func(x, y, half);
    int b = func(x + half, y, half);
    int c = func(x, y + half, half);
    int d = func(x + half, y + half, half);

    int temp[4] = {a, b, c, d};
    sort(temp, temp + 4);
    return temp[2];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            cin >> arr[i][j];
    }

    cout << func(1, 1, n);
}