#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int arr[1001][1001]; // 입력 받을 배열
int visit[1001][1001]; // 0 그룹화 시킬때 필요한 배열
int result[1001][1001]; // 결과 배열
bool check[1001][1001];
int N, M;
int zeroGroup[500001]; // 각 그룹의 0의 개수
int zeroGroupCount = 1; // 그룹 개수
void bfs(int i, int j); // 벽이 아닌 부분을 그룹화해줌
void find(int i, int j); // 벽을 부시면 몇칸을 갈 수 있는지 세주는 함수
int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < M; j++) {
			char c = s[j];
			int d = c - '0';
			arr[i][j] = d;
		}
	}

	
	for (int i = 0; i < N; i++) { // 0부분 그룹화시키기
		for (int j = 0; j < M; j++) {
			if (arr[i][j] == 0 && check[i][j] == false) { 
				bfs(i, j);
			}
		}
	}

	for (int i = 0; i < N; i++) { 
		for (int j = 0; j < M; j++) {
			if (arr[i][j] == 1) {
				find(i, j);
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
			cout << result[i][j]%10;
		cout << '\n';
	}

}
void bfs(int i, int j) { // 각각의 0에 그룹번호를 새겨주고, 그 그룹개수는 zerosum에 푸쉬
	queue<pair<int, int>>q;
	q.push({ i,j });
	visit[i][j] = zeroGroupCount;
	int zerocount = 0;
	check[i][j] = true;
	while (!q.empty()) {
		zerocount++;
		pair<int, int>cur = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int mx = cur.first + dx[i];
			int my = cur.second + dy[i];
			if (mx < 0 || my < 0 || mx >= N || my >= M)
				continue;
			if (arr[mx][my] == 1||check[mx][my])
				continue;
			q.push(make_pair(mx, my));
			visit[mx][my] = zeroGroupCount;
			check[mx][my] = true;
		}
	}
	zeroGroup[zeroGroupCount] = zerocount;
	zeroGroupCount++;	
}
void find(int i, int j) {
	vector<int>v;
	for (int k = 0; k < 4; k++) {
		bool f = true;
		int mx = i + dx[k];
		int my = j + dy[k];
		if (mx < 0 || my < 0 || mx >= N || my >= M)
			continue;
		if (arr[mx][my] == 1)
			continue;
		v.push_back(visit[mx][my]);
	}
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	for (int x = 0; x < v.size(); x++)
		result[i][j] += zeroGroup[v[x]];
	result[i][j] += 1;
}