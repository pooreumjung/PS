#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int k, l;
    cin >> k >> l;

    unordered_map<string, int> latestApplyTime;
    vector<string> applyOrder;

    for (int i = 0; i < l; ++i) {
        string id;
        cin >> id;
        // 처음 신청한 경우만 순서 기록
        if (latestApplyTime.find(id) == latestApplyTime.end()) {
            applyOrder.push_back(id);
        }
        // 마지막 신청 시간 갱신
        latestApplyTime[id] = i;
    }

    // 신청 순서대로 다시 정렬 (마지막 신청 기준)
    sort(applyOrder.begin(), applyOrder.end(), [&](const string &a, const string &b) {
        return latestApplyTime[a] < latestApplyTime[b];
    });

    int cnt = 0;
    for (auto &id : applyOrder) {
        if (cnt >= k) break;
        cout << id << '\n';
        cnt++;
    }

}