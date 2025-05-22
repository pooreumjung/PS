#include<iostream>
#include<vector>
using namespace std;
#define MAX 1001
int N, M;

vector<int> arr[MAX]; // 각 그룹의 정보를 저장할 배열
int d[MAX]; // 각 번호에 출발지를 저장할 배열
bool visit[MAX]; // 방문할 수 있는지를 체크할 배열
bool dfs(int node); // 매칭이 가능하면 true를, 불가능하면 false를 return
int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		int work;
		cin >> work;
		while (work--) {
			int number;
			cin >> number;
			arr[i].push_back(number);
		}
	}

	int count = 0;
	for (int i = 1; i <= N; i++) {
		fill(visit, visit + MAX, false);
		if (dfs(i))
			count++;
	}
	cout << count;
}

bool dfs(int node)
{
	// 연결된 모든 노드에 대해서 들어갈 수 있는지 탐색
	for (int i = 0; i < arr[node].size(); i++) {
		int end = arr[node][i]; // 가려고자 하는 목적지
		if (visit[end]) // 이미 처리가 되었다면 pass
			continue;
		visit[end] = true; 
		if (d[end] == 0 || dfs(d[end])) {
			d[end] = node;
			return true;
		}
	}
	return false;
}
