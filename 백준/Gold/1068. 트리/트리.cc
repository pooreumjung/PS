#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>>tree;
vector<bool>visit;
vector<int>answer;
vector<int>temp;
void dfs(int number);
int N;
int node;
int ans = 0;
int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	tree.resize(N);
	visit.resize(N);
	answer.resize(N);

	fill(visit.begin(), visit.end(), false);
	fill(answer.begin(), answer.end(), -2);
	int root;
	for (int i = 0; i < N; i++) { //인접 리스트 구현
		int a;
		cin >> a;
		if (a == -1)
			root = i;
		else {
			tree[i].push_back(a);
			tree[a].push_back(i);
		}
	}
	cin >> node;
	if (node == root) {
		cout << 0;
		return 0;
	}
	else {
		dfs(root); // 루트 노드부터 dfs탐색
		cout << ans;
	}
}
void dfs(int number) { // 탐색 완료
	visit[number] = true;
	int cnode = 0;

	for (int i : tree[number]) {
		if (!visit[i]&&i!=node) {
			answer[i] = number;
			cnode++;
			dfs(i);
		}
	}
	if (cnode == 0)
		ans += 1;
}
