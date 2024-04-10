#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

typedef pair< int, int>edge;
int N, M, u, v, w;
vector<edge>edges[101]; // 에지 리스트 
long mdist[101];
int before[101];
void bellmanFord();
int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		cin >> u >> v >> w;
		edges[u].push_back({ v,-w });
	}

	bellmanFord();	
}

void bellmanFord()
{

	fill(mdist, mdist + 101, LONG_MAX);
	mdist[1] = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 1; j < N+1; j++) {
			for (edge tmp : edges[j]) {
				int start = j;
				int end = tmp.first;
				int value = tmp.second;
				if (mdist[start] != LONG_MAX && mdist[end] > mdist[start] + value) {
					mdist[end] = mdist[start] + value;
					before[end] = start;
					if (i == N - 1)
						mdist[end] = -LONG_MAX;
				}
			}
		}
	}

	if (mdist[N] == LONG_MAX || mdist[N] == -LONG_MAX)
		cout << -1;
	else
	{
		vector<int>path; // 경로 출력 배열
		int s = N;
		while (s != 0) {
			path.push_back(s);
			s = before[s];
		}
		for (int i = path.size() - 1; i >= 0; i--)
			cout << path[i] << " ";
	}
	return;
}
