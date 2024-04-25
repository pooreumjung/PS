#include<iostream>
using namespace std;

int arr[301][301];
int dSum[301][301];
int resultSum(int a, int b, int x, int y);
int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> arr[i][j];
		}
	}
	
	for(int i=1;i<=N;i++){
		for (int j = 1; j <= M; j++) {
			dSum[i][j] = dSum[i - 1][j] + dSum[i][j - 1] - dSum[i - 1][j - 1] + arr[i][j];
		}
	}
	
	int K;
	cin >> K;

	while (K--) {
		int i, j, x, y;
		cin >> i >> j >> x >> y;
		cout << resultSum(i, j, x, y) << "\n";
	}


}

int resultSum(int a, int b, int x, int y)
{
	int res = 0;
	if (a == x && b == y)
		return arr[a][b];

	res = dSum[x][y] - dSum[a - 1][y] - dSum[x][b - 1] + dSum[a - 1][b - 1];
	return res;

}
