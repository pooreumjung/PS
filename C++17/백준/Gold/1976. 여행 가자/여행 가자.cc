#include<iostream>
#include<vector>
using namespace std;
vector<int>parent;

void Union(int a, int b);
int find(int a);

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N,M;
	cin >> N>>M;
	int A[201][201];

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> A[i][j]; // 정보 입력받기
		}
	}

	int travel[1001];
	for (int i = 1; i <= M; i++) {
		cin >> travel[i];
	}

	parent.resize(N + 1);
	for (int i = 0; i <= N; i++)
		parent[i] = i; // 초기 배열 설정
	
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (A[i][j] == 1)
				Union(i, j);
		}
	}
	
	int res = find(travel[1]);
	bool check = true;

	for (int i = 2; i <= M; i++) {
		int node = find(travel[i]);
		if (node != res) {
			check = false;
			break;
		}
	}

	if (check)
		cout << "YES";
	else
		cout << "NO";
}

void Union(int a, int b) {
	int node1 = find(a);
	int node2 = find(b);

	if (node1 != node2)
		parent[node2] = node1;
}

int find(int a) {
	if (parent[a] == a)
		return a;
	else
		return parent[a] = find(parent[a]);
}