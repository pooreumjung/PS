#include <vector>
#include <queue>

static int dx[] = {0, 0, 1, -1};
static int dy[] = {1, -1, 0, 0};

int solution(std::vector<std::vector<int>> maps)
{
    int N = maps.size();
    int M = maps[0].size();

    std::queue<int> q;
    q.push(0);

    maps[0][0] = 2;

    while(!q.empty()) {
        int cur = q.front();
        q.pop();

        int y = cur / M;
        int x = cur % M;

        if(y == N - 1 && x == M - 1)
            return maps[y][x] - 1;

        for(int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if(ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
            if(maps[ny][nx] != 1) continue;

            maps[ny][nx] = maps[y][x] + 1;
            q.push(ny * M + nx);
        }
    }

    return -1;
}