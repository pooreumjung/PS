#include<iostream>
#include<queue>
#include<vector>
#include<limits.h>
using namespace std;

typedef pair<int, int>edge;
int mlist[1001][1001];
priority_queue<int>mdistance[1001];
int n, m, k;
int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m >> k;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		mlist[a][b] = c; // 인접 리스트 초기화
	}
	priority_queue<edge, vector<edge>, greater<edge>>q;
	q.push({ 0,1 });
	mdistance[1].push(0);

	while (!q.empty()) {
		edge tmp = q.top();
		q.pop();
		for (int i=1;i<=n;i++) {
			if (mlist[tmp.second][i] != 0) {
				if (mdistance[i].size() < k) {
					mdistance[i].push(tmp.first + mlist[tmp.second][i]);
					q.push({ tmp.first + mlist[tmp.second][i],i });
				}
				else if (mdistance[i].top() > tmp.first + mlist[tmp.second][i]) {
					mdistance[i].pop();
					mdistance[i].push(tmp.first + mlist[tmp.second][i]);
					q.push({ tmp.first + mlist[tmp.second][i],i });
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		if (mdistance[i].size() == k)
			cout << mdistance[i].top() << '\n';
		else
			cout << -1 << '\n';
	}
}