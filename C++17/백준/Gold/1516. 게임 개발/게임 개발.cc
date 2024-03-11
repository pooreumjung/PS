#include<iostream>
#include<queue>
#include<vector>
using namespace std;

vector<int>buildTime; // time을 저장할 배열
vector<vector<int>>A; // 입력받을 인접 리스트
vector<int>indegree; // 진입 차수 배열
vector<int>result; // 결과 출력 배열

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	buildTime.resize(N + 1); // 시간 배열 크기 조정
	A.resize(N + 1); // 인접 리스트 크기 조정
	indegree.resize(N + 1); // 진입 차수 배열 크기 조정
	result.resize(N + 1); // 결과 배열 크기 조정

	for (int i = 0; i <= N; i++) // 진입 차수 배열 0으로 초기화
		indegree[i] = 0;

	for (int i = 1; i <= N; i++) {
		int money;
		cin >> money;
		buildTime[i] = money; // 시간 입력
		while (true) {
			int x;
			cin >> x;
			if (x == -1)
				break;
			A[x].push_back(i); // 인접 리스트 업데이트
			indegree[i]++; // 진입 차수 배열 업데이트
		}
	}

	for (int i = 1; i <= N; i++) // 진입 차수 배열 0으로 초기화
		result[i] = 0;

	queue<int>myQueue;
	for (int i = 1; i <= N; i++) { // 진입 차수 0인 값들 큐에 푸쉬
		if (indegree[i] == 0) {
			myQueue.push(i);
		}
	}

	while (!myQueue.empty()) {
		int now = myQueue.front();
		myQueue.pop();
		for (int next : A[now]) {
			indegree[next]--;
			result[next] = max(result[next], result[now] + buildTime[now]);
			if (indegree[next] == 0)
				myQueue.push(next);
		}
	}

	for (int i = 1; i <= N; i++)
		cout << result[i]+buildTime[i]<< '\n';
}