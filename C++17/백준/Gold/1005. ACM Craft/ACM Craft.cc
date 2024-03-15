#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		int building, k;
		cin >> building >> k;

		vector<vector<int>>list;
		vector<int>buildtime;
		vector<int>indegree;

		buildtime.resize(building + 1);
		list.resize(building + 1);
		indegree.resize(building + 1);

		for (int j = 1; j <= building; j++) { // 건물시간 입력
			int time;
			cin >> time;
			buildtime[j] = time;
		}
		for (int x = 0; x < k; x++) { // 인접 리스트 구현 및 진입 차수 배열 업데이트
			int start, end;
			cin >> start >> end;
			list[start].push_back(end);
			indegree[end]++;
		}
		int last;
		cin >> last;

		queue<int>pq;
		for (int i = 1; i <= building; i++) {
			if (indegree[i] == 0)
				pq.push(i);
		}
		vector<int>result;
		result.resize(building + 1);
		fill(result.begin(), result.end(), 0);
		while (!pq.empty()) {
			int now = pq.front();
			pq.pop();
			int min1 = -1;
			for (int next : list[now]) {
				indegree[next]--;
				result[next] = max(result[next], result[now] + buildtime[now]);
				if (indegree[next] == 0) {
					pq.push(next);
				}
			}

		}
		cout << result[last] + buildtime[last] << '\n';
	}

}