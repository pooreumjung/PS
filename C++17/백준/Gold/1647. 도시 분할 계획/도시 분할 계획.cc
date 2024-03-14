#include<iostream>
#include<vector>
#include<queue>
using namespace std;

typedef struct edge {
	int start, end, value;
	bool operator > (const edge& temp)const {
		return value > temp.value;
	}
}edge;
vector<int>parent;
priority_queue<edge, vector<edge>, greater<edge>>pq;
priority_queue<edge, vector<edge>, greater<edge>>q;
void Union(int start, int end);
int find(int a);
int search(int node);
int N, M;
int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;

	parent.resize(N + 1);
	for (int i = 0; i <= N; i++)
		parent[i] = i;

	for (int i = 0; i < M; i++) {
		int start, end, value;
		cin >> start >> end >> value;
		pq.push(edge{ start,end,value });
	}

	int sum = 0, ncount = 0;
	while (ncount < N - 2) {
		edge cur = pq.top();
		q.push(cur);
		pq.pop();
		if (find(cur.start) != find(cur.end)) {
			ncount++;
			sum += cur.value;
			Union(cur.start, cur.end);
		}
	}
	/*int min = 9999999;
	for (int i = 1; i <= N; i++) {
		int temp = parent[i]; // 임시값 저장
		parent[i] = i; // 연결 끊어버리기
		int a = search(i);
		if (a < min)
			min = a;
		parent[i] = temp;
	}*/
	cout << sum;
}
void Union(int start, int end) {
	int node1 = find(start);
	int node2 = find(end);

	if (node1 != node2)
		parent[node2] = node1;
}
int find(int a) {
	if (a == parent[a])
		return a;
	else
		return parent[a] = find(parent[a]);
}
int search(int node) {
	priority_queue<edge, vector<edge>, greater<edge>>q2;
	priority_queue<edge, vector<edge>, greater<edge>>q3;
	while (!q.empty()) {
		edge cur = q.top();
		q2.push(cur);
		q3.push(cur);
		q.pop();
	}
	int edgecount = 0;
	int sum1 = 0;
	int sum2 = 0;
	while (edgecount < N - 2) { // 엣지가 1개더 빠져야됨
		edge cur = q2.top();
		int start = cur.start;
		int end = cur.end;
		int value = cur.value;
		q2.pop();
		if (find(start) == find(end)) {
			sum1 += value;
			edgecount++;
		}
	}
	while (!q3.empty()) {
		edge cur = q3.top();
		q.push(cur);
		q3.pop();
	}

	return sum1;

}