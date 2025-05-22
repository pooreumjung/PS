#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>>tree;
vector<bool>visit;
vector<int>parent;
void dfs(int number);
int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	tree.resize(N + 1);
	for (int i = 0; i < N-1; i++) { // 인접 리스트 입력 완료
		int node1, node2;
		cin >> node1 >> node2;
		tree[node1].push_back(node2);
		tree[node2].push_back(node1);
	}

	visit.resize(N + 1); // 방문 배열 부모 배열 모두 초기화
	parent.resize(N + 1);
	fill(visit.begin(), visit.end(), false);
	fill(parent.begin(), parent.end(), 0);

	dfs(1);

	for (int i = 2; i <= N; i++)
		cout << parent[i] << '\n';
}
void dfs(int number) {
	visit[number] = true;

	for (int i : tree[number]) {
		if (visit[i] == false) {
			parent[i] = number;
			dfs(i);
		}
	}
}

