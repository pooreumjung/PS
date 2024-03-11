#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

void Union(int a, int b);
int find(int a);
vector<int>friendcost;
vector<int>parent; // union
int check[10001];
int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, K;
	cin >> N >> M >> K;

	friendcost.resize(N + 1);
	parent.resize(N + 1);
	for (int i = 0; i <= N; i++) // parent배열 초기화
		parent[i] = i;

	for (int i = 1; i <= N; i++) { // 친구비용 저장
		int money;
		cin >> money;
		friendcost[i] = money;
	}

	for (int i = 0; i < M; i++) {
		int start, end;
		cin >> start >> end;
		Union(start, end);
	}

	long sum = 0;
	unordered_set<int>S;
	for (int i = 1; i <= N; i++) {
		S.insert(find(i));
	}
	for (auto it : S)
		sum += friendcost[it];
	if (sum <= K)
		cout << sum;
	else
		cout << "Oh no";
}
void Union(int a, int b) {
	int node1 = find(a);
	int node2 = find(b);

	if (node1 != node2) {
		if (friendcost[node1] > friendcost[node2])
			parent[node1] = node2;
		else
			parent[node2] = node1;
	}
}
int find(int a) {
	if (a == parent[a])
		return a;
	else
		return parent[a] = find(parent[a]);
}