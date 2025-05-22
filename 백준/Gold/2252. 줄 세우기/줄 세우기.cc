#include<iostream>
#include<queue>
#include<vector>
using namespace std;

queue<int>tp; // 위상 정렬 배열
vector<int>D; // 진입 차수 배열
vector<vector<int>>A; // 입력받을 인접 리스트

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;
	A.resize(N + 1); // 인접 리스트 크기 초기화
	for (int i = 0; i < M; i++) { // 인접 리스트 입력
		int a, b;
		cin >> a >> b;
		A[a].push_back(b); // a가 더 작으므로 a가 b를 가리킨다
	}

	D.resize(N + 1); // 진입 차수 배열 크기 초기화
	for (int i = 0; i < D.size(); i++) // 초기값 0으로 초기화
		D[i] = 0;
	for (int i = 0; i <= N; i++) { // 진입 차수 배열 조절
		for (int j = 0; j < A[i].size(); j++) {
			int index = A[i][j];
			D[index]++; 
		}
	}
	int check = 0;
	while (check!=N) {
		for (int i = 1; i <= N; i++) {
			if (D[i] == 0) { // 진입 차수가 0인 부분 찾기
				check++;
				D[i] = -1;
				tp.push(i); // 위상 정렬 배열에 넣어주고
				for (int j = 0; j < A[i].size(); j++) {
					int index = A[i][j]; // 진입 차수가 0인 애들이 가리키는 값
					D[index]--; // 진입 차수 배열 정비
				}
			}
		}
	}
	while (!tp.empty()) {
		int j = tp.front();
		cout << j << " ";
		tp.pop();
	}
		
}