#include<iostream>
#include<vector>
#include<tuple>
#include<limits.h>
using namespace std;
typedef tuple<int, int, int>edge;
vector<edge>edges;
vector<long>mdistance;
int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;
	mdistance.resize(N + 1);
	fill(mdistance.begin(), mdistance.end(),LONG_MAX); // 최단 거리 배열 초기화

	for (int i = 0; i < M; i++) { // 그래프 구현
		int start, end, value;
		cin >> start >> end >> value;
		edges.push_back(make_tuple(start, end, value));
	}
	
	mdistance[1] = 0; // 출발 노드 최단 거리 0으로 초기화

	for (int i = 1; i < N; i++) { // N-1만큼
		for (int j = 0; j < M; j++) {
			edge medge = edges[j];
			int start = get<0>(medge);
			int end = get<1>(medge);
			int value = get<2>(medge);
			if (mdistance[start] != LONG_MAX && mdistance[end] > mdistance[start] + value) // 더 가까운 최단 거리 갱신
				mdistance[end] = mdistance[start] + value;
		}
	}

	bool mycycle = false;

	for (int i = 0; i < M; i++) {
		edge medge = edges[i];
		int start = get<0>(medge);
		int end = get<1>(medge);
		int value = get<2>(medge);
		if (mdistance[start] != LONG_MAX && mdistance[end] > mdistance[start] + value)
			mycycle = true;
	}

	if (!mycycle) {
		for (int i = 2; i <= N; i++) {
			if (mdistance[i] == LONG_MAX)
				cout << -1 << '\n';
			else
				cout << mdistance[i] << '\n';
		}
	}
	else
		cout << -1 << '\n';
	
}