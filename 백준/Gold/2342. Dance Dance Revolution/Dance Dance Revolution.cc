#include <iostream>
#include <cmath>
#include <climits>
using namespace std;

long dp[100001][5][5];
int mp[5][5] = { { 0, 2, 2, 2, 2 },
                 { 2, 1, 3, 4, 3 },
                 { 2, 3, 1, 3, 4 },
                 { 2, 4, 3, 1, 3 },
                 { 2, 3, 4, 3, 1 } };

int main()
{
    int n = 0, s = 1;
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            for (int k = 0; k < 100001; k++)
                dp[k][i][j] = 100001 * 4;
    dp[0][0][0] = 0;

    while (true) {
        cin >> n;
        if (n == 0)
            break;
        for (int i = 0; i < 5; i++) {
            if (n == i)
                continue;
            for (int j = 0; j < 5; j++) {

                dp[s][i][n] = min(dp[s - 1][i][j] + mp[j][n], dp[s][i][n]);
            }
        }
        for (int j = 0; j < 5; j++) {
            if (n == j)
                continue;
            for (int i = 0; i < 5; i++) {

                dp[s][n][j] = min(dp[s - 1][i][j] + mp[i][n], dp[s][n][j]);
            }
        }
        s++;
    }
    s--;
    long minVal = INT_MAX;
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            minVal = min(minVal, dp[s][i][j]);
    cout << minVal << "\n";
}

/*

	수열 입력받는 배열 : move
	입력받는 값이 0일 때까지 move를 입력받기

	각 발이 이동하느 ㄴ것에 대한 최솟값 미리 지정 
	mp[start][end] => start부터 end까지 이동할 때 드는 최소 힘

	dp[N][L][R] => N번째 수열만큼 움직였을 때 왼쪽발과 오른쪽
	              발의 위치까지 이동할 때 드는 최소 누적힘

    for문 돌리면서
    왼쪽발이 움직일때와
    오른쪽발이 움직일때를 따로따로 구해주기

    그런다음 최솟값 출력


*/