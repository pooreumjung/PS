#include<iostream>
#include<tuple>
#include<limits.h>
#include<vector>
using namespace std;

typedef tuple<int, int, int>edge;
vector<edge>edges;
vector<long>mdistance;
vector<long>citymoney;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, startcity, endcity, M;
	cin >> N >> startcity >> endcity >> M;

	mdistance.resize(N); // 최단 거리 배열 크기 조절
	citymoney.resize(N); // 도시 비용 배열 크기 조절
	fill(mdistance.begin(), mdistance.end(), LONG_MIN); // 최소값으로 초기화

	for (int i = 0; i < M; i++) { // 에지 리스트 업데이트
		int start, end, money;
		cin >> start >> end >> money;
		edges.push_back(make_tuple(start, end, money));
	}
	for (int i = 0; i < N; i++)
		cin >> citymoney[i];

	mdistance[startcity] = citymoney[startcity];

	for (int i = 0; i <= N+50; i++) {
		for (int j = 0; j < M; j++) {
			edge medge = edges[j];
			int start = get<0>(medge);
			int end = get<1>(medge);
			int cost = get<2>(medge);
			if (mdistance[start] == LONG_MIN)
				continue;
			else if (mdistance[start] == LONG_MAX)
				mdistance[end] = LONG_MAX;
			else if (mdistance[end] < mdistance[start]+citymoney[end]- cost) {
				mdistance[end] = mdistance[start] +citymoney[end]- cost;
				if (i >= N - 1)
					mdistance[end] = LONG_MAX;
			}
		}
	}
	if (mdistance[endcity] == LONG_MIN)
		cout << "gg";
	else if (mdistance[endcity] == LONG_MAX)
		cout << "Gee";
	else
		cout << mdistance[endcity];
}