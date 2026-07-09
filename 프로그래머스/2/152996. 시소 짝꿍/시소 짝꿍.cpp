#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

long long solution(vector<int> weights) {
    long long answer = 0;
    unordered_map<int, long long> cnt;

    sort(weights.begin(), weights.end());

    for (int w : weights) {
        // 1:1
        answer += cnt[w];

        // 2:3 관계
        if (w * 2 % 3 == 0)
            answer += cnt[w * 2 / 3];

        // 2:4 관계 = 1:2
        if (w % 2 == 0)
            answer += cnt[w / 2];

        // 3:4 관계
        if (w * 3 % 4 == 0)
            answer += cnt[w * 3 / 4];

        cnt[w]++;
    }

    return answer;
}