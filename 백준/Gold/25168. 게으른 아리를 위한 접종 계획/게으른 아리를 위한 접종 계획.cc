#include<iostream>
#include<queue>
#include<vector>
#include<limits.h>
using namespace std;

typedef pair<int, int>cur;
vector<vector<cur>>mlist;
vector<int>ans;
vector<int>indegree;
int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;
	mlist.resize(N + 1);
	indegree.resize(N + 1);
	ans.resize(N + 1);


	for (int i = 0; i < M; i++) {
		int start, end, time;
		cin >> start >> end >> time;
		mlist[start].push_back(make_pair(end, time));
		indegree[end]++;
	}

	queue<int>q;
	for (int i = 1; i <= N; i++) {
		if (indegree[i] == 0) {
			q.push(i);
			ans[i] = 1;
		}
	}

	while (!q.empty()) {
		int node = q.front();
		q.pop();
		for (cur temp : mlist[node]) {
			int next = temp.first;
			int time = temp.second;
			indegree[next]--;
			if(time>=7)
				ans[next] = max(ans[next], ans[node] + time+1);
			else
				ans[next] = max(ans[next], ans[node] + time);
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