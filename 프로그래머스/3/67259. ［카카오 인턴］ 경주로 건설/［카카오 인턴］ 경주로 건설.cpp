#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>

using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int bfs(int rowSize, int columnSize, int startDir, vector<vector<int>> board) {
    const int INF = 999999;

    // x, y, 현재 방향
    queue<tuple<int, int, int>> q;

    // cost[x][y][dir]
    // (x, y)에 dir 방향으로 도착했을 때의 최소 비용
    vector<vector<vector<int>>> cost(
        rowSize,
        vector<vector<int>>(columnSize, vector<int>(4, INF))
    );

    q.push({0, 0, startDir});
    cost[0][0][startDir] = 0;

    while (!q.empty()) {
        auto [curX, curY, curDir] = q.front();
        q.pop();

        int curCost = cost[curX][curY][curDir];

        for (int nextDir = 0; nextDir < 4; nextDir++) {
            int nx = curX + dx[nextDir];
            int ny = curY + dy[nextDir];

            if (nx < 0 || ny < 0 || nx >= rowSize || ny >= columnSize) continue;
            
            if (board[nx][ny] == 1) continue;
            
            int nextCost = curCost + 100;

            // 직전 방향과 달라지면 코너 비용 추가
            if (curDir != nextDir) nextCost += 500;
            
            // 같은 위치·방향으로 더 저렴하게 도착한 경우만 갱신
            if (nextCost < cost[nx][ny][nextDir]) {
                cost[nx][ny][nextDir] = nextCost;
                q.push({nx, ny, nextDir});
            }
        }
    }

    return min({
        cost[rowSize - 1][columnSize - 1][0],
        cost[rowSize - 1][columnSize - 1][1],
        cost[rowSize - 1][columnSize - 1][2],
        cost[rowSize - 1][columnSize - 1][3]
    });
}

int solution(vector<vector<int>> board) {
    int rowSize = board.size();
    int columnSize = board[0].size();

    // 시작점에서는 오른쪽 또는 아래로만 출발
    return min(
        bfs(rowSize, columnSize, 0, board), // 오른쪽
        bfs(rowSize, columnSize, 1, board)  // 아래
    );
}