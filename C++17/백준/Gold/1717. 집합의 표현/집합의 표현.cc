#include<iostream>
#include<vector>
using namespace std;

vector<int>A;
void Union(int a, int b);
int find(int a);
int node = -1;
int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	A.resize(n + 1);
	for (int i = 0; i <= n; i++)
		A[i] = i;

	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;
		int a, b;
		cin >> a >> b;
		if (x == 0)
			Union(a, b);
		else if (x == 1) {
			int in1 = find(a);
			int in2 = find(b);
			if (in1 == in2)
				cout << "YES" << '\n';
			else
				cout << "NO" << '\n';
		}

	}
}
void Union(int a, int b) {
	int MAX = max(a, b);
	int MIN = min(a, b);

	if (A[a] == a && A[b] == b) { //둘 다 아무런 노드와 연결이 되어 있지 않다면
		A[MAX] = MIN; // 더 작은 값을 대표 노드로 설정
	}

	else { // 그게 아니라면 둘다 대표 노드값을 찾기
		int node1 = find(a); //a의 대표노드
		int node2 = find(b); //b의 대표노드
		int MAX1 = max(node1, node2);
		int MIN1 = min(node1, node2);
		A[MAX1] = MIN1; // 더 작은 값을 대표노드로
	}
}
int find(int a) {
	if (a == A[a])
		return a;
	return A[a] = find(A[a]);

}