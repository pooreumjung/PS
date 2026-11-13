#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9;

int solution(int alp, int cop, vector<vector<int>> problems) {
    int max_alp = 0, max_cop = 0;

    // 1. 목표 알고력, 코딩력 계산
    for (const auto& problem : problems) {
        max_alp = max(max_alp, problem[0]);
        max_cop = max(max_cop, problem[1]);
    }

    // 2. 시작 능력이 목표를 초과하는 경우 처리
    alp = min(alp, max_alp);
    cop = min(cop, max_cop);

    // 3. DP 초기화
    vector<vector<int>> dp(
        max_alp + 1,
        vector<int>(max_cop + 1, INF)
    );

    dp[alp][cop] = 0;

    // 4. DP 계산
    for (int a = alp; a <= max_alp; a++) {
        for (int c = cop; c <= max_cop; c++) {

            if (dp[a][c] == INF)
                continue;

            // 알고리즘 공부
            if (a < max_alp) {
                dp[a+1][c] = min(
                    dp[a+1][c],
                    dp[a][c] + 1
                );
            }

            // 코딩 공부
            if (c < max_cop) {
                dp[a][c+1] = min(
                    dp[a][c+1],
                    dp[a][c] + 1
                );
            }

            // 문제 풀기
            for (const auto& p : problems) {
                int reqAlp = p[0];
                int reqCop = p[1];
                int rewardAlp = p[2];
                int rewardCop = p[3];
                int cost = p[4];

                if (a < reqAlp || c < reqCop)
                    continue;

                int nextAlp = min(max_alp, a + rewardAlp);
                int nextCop = min(max_cop, c + rewardCop);

                dp[nextAlp][nextCop] = min(
                    dp[nextAlp][nextCop],
                    dp[a][c] + cost
                );
            }
        }
    }

    return dp[max_alp][max_cop];
}