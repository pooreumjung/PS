#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<vector<int>>A;
vector<int>answer;
vector<bool>visit;
void bfs(int node);

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;
	A.resize(N + 1);
	visit.resize(N + 1);
	answer.resize(N + 1);

	for (int i = 0; i < M; i++) {
		int start, end;
		cin >> start >> end;
		A[start].push_back(end);
	}
		
	for (int i = 0; i <= N; i++) {
		fill(visit.begin(), visit.end(), false);
		bfs(i);
	}
	int max1 = 0;

	for (int i = 1; i <= N; i++) {
		if (max1 < answer[i])
			max1 = answer[i];
	}
	for (int i = 1; i <= N; i++) {
		if (answer[i] == max1)
			cout << i<< '\n';
	}
}
void bfs(int node) {
	queue<int>myQueue;
	myQueue.push(node);
	visit[node] = true;
	while (!myQueue.empty()) {
		int now_node = myQueue.front();
		myQueue.pop();
		for (int i : A[now_node]) {
			if (visit[i] == false) {
				myQueue.push(i);
				answer[i]++;
				visit[i] = true;
			}
		}

	}

}