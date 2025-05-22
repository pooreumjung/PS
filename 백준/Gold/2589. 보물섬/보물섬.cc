#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node
{
	int y, x, depth;
};

const int dy[4] = { -1,1,0,0 };
const int dx[4] = { 0,0,-1,1 };

int N, M, ret;
char adj[50][50];
bool visited[50][50];
vector<pair<int, int>> v;

void bfs(int sy, int sx)
{
	// 초기화
	fill(&visited[0][0], &visited[0][0] + 50 * 50, false);
	queue<Node> q;

	// 첫 시작값
	q.push({ sy,sx,0 });
	visited[sy][sx] = true;

	while (q.size())
	{
		int y = q.front().y;
		int x = q.front().x;
		int depth = q.front().depth;
		q.pop();

		// 가장 depth가 큰거 찾기
		ret = max(depth, ret);

		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || ny >= N || nx < 0 || nx >= M)
				continue;
			if (visited[ny][nx])
				continue;
			if (adj[ny][nx] == 'W')
				continue;

			visited[ny][nx] = true;
			q.push({ ny,nx,depth + 1 });
		}
	}
}



int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	for (int y = 0; y < N; y++)
		for (int x = 0; x < M; x++)
		{
			cin >> adj[y][x];
			// 육지인거 v에 넣기
			if (adj[y][x] == 'L')
				v.push_back({ y,x });
		}
	
	// 육지인 좌표 dfs
	for (int i = 0; i < v.size(); i++)
		bfs(v[i].first, v[i].second);

	cout << ret;


	return 0;
}