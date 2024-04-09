#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<memory.h>
#include<limits.h>
using namespace std;

int TC,scent,crossnode1,crossnode2;
int n, m, t, s, g, h, a, b, d, x;
int result_1[50001], result_2[50001];
vector<int>ans;
typedef pair<int, int>edge;
vector<edge>road[50001];
void dijkstra(int start, int* result);

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> TC;

	while (TC--) {
		// 배열값들 모두 초기화
		ans.clear();
		memset(result_1, 0, sizeof(result_1));
		memset(result_2, 0, sizeof(result_2));
		for (int i = 0; i < 50001; i++)
			road[i].clear();

		cin >> n >> m >> t;
		cin >> s >> g >> h;

		for (int i = 0; i < m; i++) {
			cin >> a >> b >> d;
			road[a].push_back(edge(b, d));
			road[b].push_back(edge(a, d));
			if (a == g && b == h || a == h && b == g)
				scent = d;
		}

		// 출발점에서 돌리기
		dijkstra(s, result_1);

		if (result_1[g] > result_1[h]) {
			crossnode1 = h;
			crossnode2 = g;

		}
		else {
			crossnode1 = g;
			crossnode2 = h;
		}

		dijkstra(crossnode2, result_2);

		for (int i = 0; i < t; i++) {
			cin >> x;
			if (result_1[x] == result_1[crossnode1] + scent + result_2[x])
				ans.push_back(x);
		}

		sort(ans.begin(), ans.end());
		for (int i = 0; i < ans.size(); i++)
			cout << ans[i] << " ";
		cout << '\n';
	}

}

void dijkstra(int start, int* result)
{
	queue<int>q;
	for (int i = 1; i <= n; i++)
		result[i] = INT_MAX;
	result[start] = 0;
	q.push(start);

	while (!q.empty()) {

		int node = q.front();
		int dist = result[node];
		q.pop();

		for (int i = 0; i < road[node].size(); i++) {
			int next_node = road[node][i].first;
			int next_dist = road[node][i].second;

			if (result[next_node] > dist + next_dist) {
				result[next_node] = dist + next_dist;
				q.push(next_node);
			}
		}
	}

}
