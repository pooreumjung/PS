#include<iostream>
#include<vector>
#include<queue>
#include<limits.h>
using namespace std;

vector<int>workTime;
vector<vector<int>>mlist;
vector<int>indegree;
vector<int>ans;
int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, count, f;
	cin >> N;
	workTime.resize(N + 1);
	mlist.resize(N + 1);
	indegree.resize(N + 1);
	ans.resize(N + 1);

	int c = 0;
	for (int i = 1; i <= N; i++) {
		cin >> workTime[i];
		cin >> count;
		if (count == 0)
			c++;
		for (int j = 0; j < count; j++) {
			cin >> f;
			mlist[f].push_back(i);
			indegree[i]++;
		}
	}

	queue<int>q;
	int sum = 0;
	for (int i = 1; i <= N; i++) {
		if (indegree[i] == 0) {
			q.push(i);
			ans[i] = workTime[i];
		}
	}

	while (!q.empty()) {
		int node = q.front();
		q.pop();
		for (int next : mlist[node]) {
			indegree[next]--;
			ans[next] = max(ans[next], ans[node] + workTime[next]);
			if (indegree[next] == 0)
				q.push(next);
		}
	}

	int max = INT_MIN;
	for (int i = 1; i <= N; i++) {
		if (max < ans[i])
			max = ans[i];
	}
	cout << max;
}