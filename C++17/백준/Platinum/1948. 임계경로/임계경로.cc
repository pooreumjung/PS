#include<iostream>
#include<queue>
#include<vector>
using namespace std;

vector<vector<pair<int, int>>>A;// 인접 리스트
vector<int>indegree; // 진입 차수 
vector<vector<pair<int, int>>>rev; // 역으로 가기

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;
	A.resize(N + 1);
	indegree.resize(N + 1);
	rev.resize(N + 1);

	for (int i = 0; i < M; i++) {
		int start, end, time;
		cin >> start >> end >> time;
		A[start].push_back({ end,time });
		rev[end].push_back({ start,time });
		indegree[end]++;
	}

	int startcity, endcity;
	cin >> startcity >> endcity;
	queue<int>myQueue;
	myQueue.push(startcity);
	vector<int>result;
	result.resize(N + 1);

	while (!myQueue.empty()) {
		int now = myQueue.front();
		myQueue.pop();
		for (pair<int, int>cur : A[now]) {
			indegree[cur.first]--;
			result[cur.first] = max(result[cur.first], result[now] + cur.second);
			if (indegree[cur.first] == 0)
				myQueue.push(cur.first);
		}
	}

	int citycount = 0;
	vector<bool>visit;
	visit.resize(N + 1);
	queue<int>countqueue;
	countqueue.push(endcity);
	visit[endcity] = true;

	while (!countqueue.empty()) {
		int now = countqueue.front();
		countqueue.pop();
		for (pair<int, int>cur : rev[now]) {
			if (result[now] == result[cur.first] + cur.second) {
				citycount++;

				if (visit[cur.first] == false) {
					visit[cur.first] = true;
					countqueue.push(cur.first);
				}
			}
		}
	}
	cout << result[endcity] << " " << citycount;

}