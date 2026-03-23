#include <iostream>
#include <vector>
using namespace std;

int arr[9][9];
bool visited[9][9];
vector<pair<int, int>> v;
bool possible(int x, int y, int num)
{
    // 행 검사
    for (int i = 0; i < 9; i++)
    {
        if (arr[x][i] == num)
            return false;
    }

    // 열 검사
    for (int i = 0; i < 9; i++)
    {
        if (arr[i][y] == num)
            return false;
    }

    // 3*3 검사
    int startX = (x / 3) * 3;
    int startY = (y / 3) * 3;

    for (int i = startX; i < startX + 3; i++)
    {
        for (int j = startY; j < startY + 3; j++)
        {
            if (arr[i][j] == num)
                return false;
        }
    }

    return true;
}
void func(int depth)
{
    // 모든 빈칸을 다 채움
    if (depth == v.size())
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
                cout << arr[i][j] << " ";
            cout << '\n';
        }
        exit(0);
    }

    // 시작점 잡기
    int x = v[depth].first;
    int y = v[depth].second;

    int temp[10];

    // 배열 탐색
    for (int num = 1; num <= 9; num++)
    {
        // 다음 칸으로 이동
        if (possible(x, y, num))
        {
            arr[x][y] = num;
            func(depth + 1);
            arr[x][y] = 0;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int startX, startY, total = 0;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] == 0)
                v.push_back(make_pair(i, j));
        }
    }

    func(0);
}
