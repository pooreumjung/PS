#include<iostream>
#include<queue>
using namespace std;
queue<pair<int, int>>q;
int vis[2000001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int f, s, g, u, d;
	cin >> f >> s >> g >> u >> d;
	for (int x = 0; x < 2000001; x++) {
		vis[x] = -1;
	}
	q.push({ s,0 });
	vis[s] = 0;
	while (!q.empty()) {
		int pos = q.front().first;
		int time = q.front().second;
		q.pop();
		if (pos == g) {
			cout << time;
			return 0;
		}
		int arr[2] = { pos + u,pos - d };
		for (int dir = 0; dir < 2; dir++) {
			int mp = arr[dir];
			if (mp >f||mp<=0)
				continue;
			if (vis[mp]==1)
				continue;
			q.push({ mp,time + 1 });
			vis[mp] = 1;
		}
	}
	cout << "use the stairs";
}