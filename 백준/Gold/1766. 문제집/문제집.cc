#include<iostream>
#include<queue>
#include<vector>
using namespace std;


vector<vector<int>>mlist;
vector<int>indegree;
priority_queue<int, vector<int>, greater<int>>q;
int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;
	mlist.resize(N + 1);
	indegree.resize(N + 1);


	for (int i = 0; i < M; i++) {
		int start, end;
		cin >> start >> end;
		mlist[start].push_back(end);
		indegree[end]++;
	}
	
	for (int i = 1; i <= N; i++) {
		if (indegree[i] == 0)
			q.push(i);
	}

	vector<int>ans;
	while (!q.empty()) {
		int node = q.top();
		ans.push_back(node);
		q.pop();
		for (int next : mlist[node]) {
			indegree[next]--;
			if (indegree[next] == 0)
				q.push(next);
		}
	}
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << " ";
}