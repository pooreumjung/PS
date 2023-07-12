#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
#define inf 1000000
#define Max 200001
int n, k;
int count1;
int fast;
int dis[200001];
void bfs() {
	int size = max(n, k);
	for (int x = 0; x <= size * 2; x++)
		dis[x] = inf;
	dis[n] = 0;
	queue<pair<int, int>>q;
	q.push({ n,0 });
	while (!q.empty()) {
		int pos = q.front().first;
		int time = q.front().second;
		q.pop();
		if (pos == k) {
			count1++;
			fast = time;
		}
		if (pos + 1 < Max) {
			if (time + 1 <= dis[pos + 1]) {
				dis[pos + 1] = time + 1;
				q.push({ pos + 1,time + 1 });
			}
		}
		if (pos -1 >=0 ) {
			if (time + 1 <= dis[pos - 1]) {
				dis[pos - 1] = time + 1;
				q.push({ pos - 1,time + 1 });
			}
		}
		if (pos*2 < Max) {
			if (time +1 <= dis[pos *2]) {
				dis[pos *2] = time + 1;
				q.push({ pos *2,time + 1 });
			}
		}
	}
}



int main() {
	cin >> n >> k;
	bfs();
	cout << fast << endl;
	cout << count1;
}