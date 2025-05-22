#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int N, M;
vector<int>parent; // 유니온 파인드
vector<int>v; // 위원회의 개수
vector<vector<pair<int, int>>>tree; // 각 pair쌍 저장
vector<int>alone; // 두 번째 정답 출력 배열
vector<vector<int>>s;
int arr[101][101];
int check[101];
void Union(int a, int b);
int find(int i);
int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M; // 입력받기
	tree.resize(N + 1);
	parent.resize(N + 1);
	s.resize(N + 1);

	for (int i = 1; i <= N; i++) // paernt배열 초기화
		parent[i] = i;

	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= N; j++) {
			if (i == j)
				arr[i][j] = 0;
			else
				arr[i][j] = 9876;
		}
	}

	for (int i = 0; i < M; i++) { // 각 pair쌍들 유니온 하기
		int start, end;
		cin >> start >> end;
		arr[start][end] = 1;
		arr[end][start] = 1;
		Union(start, end);
	}

	for (int i = 1; i <= N; i++) { // 각 그룹의 대표 노드를 v에 push, v의 크기가 위원회의 개수임
		if (parent[i] == i) {
			v.push_back(i);
		}
	}

	int size = v.size(); // 첫 번째 정답 출력값
	for (int i = 1; i <= N; i++) { // 각 그룹들의 크기를 check배열에 저장, 즉 check에 해당하는 인덱스는 대표 노드의 인덱스
		check[parent[i]]++;
		s[parent[i]].push_back(i);
	}

	for (int k = 1; k <= N; k++) {
		for (int s = 1; s <= N; s++) {
			for (int e = 1; e <= N; e++) {
				if (arr[s][e] > arr[s][k] + arr[k][e])
					arr[s][e] = arr[s][k] + arr[k][e];
			}
		}
	}
	
	int max_A = -1;
	int res = 9876;
	int ind = 0;


	for (int k = 0; k < v.size(); k++) {
		for (int i = 0; i < s[v[k]].size(); i++) {
			int d = s[v[k]][i];
			for (int j = 1; j <= N; j++) {
				if (arr[d][j] != 9876 && arr[d][j] > max_A) {
					max_A = arr[d][j];
				}
			}
			if (res > max_A) {
				res = max_A;
				ind = d;
			}
			max_A = -1;
		}
		alone.push_back(ind);
		res = 9876;
	}
	cout << size << '\n'; // 위원회의 갯수 출력
	sort(alone.begin(), alone.end()); // 위원들의 번호를 오름차순 정렬
	for (int i = 0; i < alone.size(); i++) // 정답 출력
		cout << alone[i] << "\n";
}
void Union(int a, int b) { // 유니온 함수 + 트리에 각 pair쌍을 저장해줌 => 나중에 플로이드 워셜을 돌릴 때 사용
	int node1 = find(a);
	int node2 = find(b);

	if (node1 == node2) {
		tree[node1].push_back({ a,b });
	}



	else if (node1 != node2) {
		if (node1 < node2) {
			parent[node2] = node1;
			tree[node1].push_back({ a,b });
		}
		else {
			parent[node1] = node2;
			tree[node2].push_back({ a,b });
		}
	}
}
int find(int a) { // 부모 노드를 반환하는 함수
	if (a == parent[a])
		return a;
	else
		return parent[a] = find(parent[a]);
}
