#include <bits/stdc++.h>
using namespace std;

int N, M;
int board[8][8];
int best = 0;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

// BFS로 바이러스 전파 후 안전 영역 개수 반환
int bfs()
{
    int tmp[8][8];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            tmp[i][j] = board[i][j]; // 원본 복사

    queue<pair<int, int>> q;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            if (tmp[i][j] == 2)
                q.push({i, j}); // 바이러스 시작점 전부 큐에

    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();
        for (int d = 0; d < 4; d++)
        {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M)
                continue;
            if (tmp[nx][ny] != 0)
                continue; // 빈 칸만 전파
            tmp[nx][ny] = 2;
            q.push({nx, ny});
        }
    }

    // 안전 영역(0) 개수 세기
    int cnt = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            if (tmp[i][j] == 0)
                cnt++;

    return cnt;
}

// 벽 3개를 완전탐색으로 세우기
void solve(int start, int wallCount)
{
    if (wallCount == 3)
    {
        best = max(best, bfs()); // 벽 3개 세웠으면 BFS
        return;
    }

    for (int i = start; i < N * M; i++)
    {
        int x = i / M;
        int y = i % M;
        if (board[x][y] == 0)
        {
            board[x][y] = 1; // 벽 세우기
            solve(i + 1, wallCount + 1);
            board[x][y] = 0; // 원상복구
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> board[i][j];

    solve(0, 0);
    cout << best;

    return 0;
}