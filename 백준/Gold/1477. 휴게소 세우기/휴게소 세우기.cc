#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    int N, M, L;
    cin >> N >> M >> L;

    vector<int> v(N);
    for (int i = 0; i < N; i++) cin >> v[i];

    // 거리 차를 구하기 위해 시작 위치와 끝 위치를 추가
    v.push_back(0);
    v.push_back(L);
    sort(v.begin(), v.end()); // 오름차순 정렬

    int start = 1;
    int end = L - 1; // 고속도로 끝에는 못지음
    int mid;
    int ans = 9999;

    // 이분탐색 시작
    while (start <= end) {
        mid = (start + end) / 2;
        int count = 0; // 현재 지은 휴게소 갯수
        // 두 휴게소 사이의 거리 차
        for (int i = 1; i < v.size(); i++) {
            int len = v[i] - v[i - 1];

            int cnt = len / mid; // 두 휴게소 사이에 지을 수 있는 휴게소 개수
            if (cnt > 0) {
                // 딱 맞아떨어진다는 것은 마지막 휴게소와 겹쳤다는 뜻이므로 하나 빼줌
                if (len % mid == 0) count += cnt - 1;
                else count += cnt;
            }
        }
        if (count > M) start = mid + 1; // 개수가 M보다 많으므로 간격 넓혀줌
        else {
            // 개수가 M보다 적으므로 간격 줄여줌
            end = mid - 1;
            // M개의 휴게소 간격이 모두 일정할 순 없음
            // 우리가 구하고자 하는 것은 최소한의 경우 중 가장 긴 것
            ans = min(ans, mid);
        }
    }
    cout << ans;
}



