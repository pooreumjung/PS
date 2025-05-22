#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<vector<int>>list; // 인접 리스트
vector<int>indegree; // 진입 차수 배열
queue<int>tp; // 위상 정렬 큐
vector<int>temp; // 임시 배열
vector<int>result;
void order(int number);
int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int singer, pd;
	cin >> singer >> pd;
	list.resize(singer + 1);
	indegree.resize(singer+1);
	for (int i = 0; i < pd; i++) { // 인접 리스트 구현
		int number;
		cin >> number;
		for (int j = 0; j < number;j++) {
			int a;
			cin >> a;
			temp.push_back(a);
		}
		order(number);
	}
	for (int i = 1; i <= singer; i++) {
		if (indegree[i] == 0)
			tp.push(i);
	}
	while (!tp.empty()) {
		int now = tp.front();
		result.push_back(now);
		tp.pop();
		for (int next : list[now]) {
			indegree[next]--;
			if (indegree[next] == 0)
				tp.push(next);
		}
	}
	bool isorder = true;
	for (int i = 1; i <= singer; i++) {
		if (indegree[i] != 0)
			isorder = false;
	}
	if (isorder) {
		for (int i = 0; i < singer; i++)
			cout << result[i] << '\n';
	}
	else
		cout << 0;

}
void order(int number) {
	for (int i = 0; i < number; i++) {
		for (int j = i + 1; j <=number-1; j++) {
			list[temp[i]].push_back(temp[j]);
			indegree[temp[j]]++; // 진입 차수 업데이트
		}
	}
	temp.clear(); // 입력 배열 초기화
}