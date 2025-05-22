#include<iostream>
#include<vector>
using namespace std;

int mdistance[101][101];
int main() {

	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;

	for (int i = 1; i <= N; i++) { // 배열 초기화
		for (int j = 1; j <= N; j++) {
			if (i == j)
				mdistance[i][j] = 0;
			else
				mdistance[i][j] = 100000;
		}
	}

	for (int i = 0; i < M; i++) {
		int start, end;
		cin >> start >> end;
		mdistance[start][end] = 1;
		mdistance[end][start] = 1;
	}

	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (mdistance[i][k] >= 1 && mdistance[k][j] >= 1) {
					mdistance[i][j] = min(mdistance[i][j], mdistance[i][k] + mdistance[k][j]);
				}
			}
		}
	}
	int sum = 100001;
	int index = 0;
	for (int i = 1; i <= N; i++) {
		int s = 0;
		for (int j = 1; j <= N; j++) {
			s += mdistance[i][j]; //각 row더해주기
		}
		if (s < sum) {
			sum = s;
			index = i;
		}
	}
	cout << index;
}