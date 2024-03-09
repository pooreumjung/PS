#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<vector<int>>A;
vector<bool>visit;
vector<int>check;
bool isEven;
void dfs(int node);

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		int V, E;
		cin >> V >> E;
		A.resize(V + 1);
		visit.resize(V + 1);
		check.resize(V + 1);
		isEven = true;

		for (int j = 0; j < E; j++) {
			int start, end;
			cin >> start >> end;
			A[start].push_back(end);
			A[end].push_back(start);
		}

		for (int k = 1; k <= V; k++) {
			if (isEven)
				dfs(k);
			else
				break;
		}
		if (isEven)
			cout << "YES" << '\n';
		else
			cout << "NO" << '\n';
		for (int i = 0; i <= V; i++) {
			A[i].clear();
			visit[i] = false;
			check[i] = 0;
		}
	}
}
void dfs(int node) {
	visit[node] = true;

	for (int i : A[node]) {
		if (!visit[i]) {
			check[i] = (check[node] + 1) % 2;
			dfs(i);
		}
		else if (check[node] == check[i]) {
			isEven = false;
		}


	}



}