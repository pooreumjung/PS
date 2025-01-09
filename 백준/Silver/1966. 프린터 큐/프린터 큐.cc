#include<bits/stdc++.h>
using namespace std;

int findMaxValue(queue<pair<int, int> > q) {
    int maxValue = -1;
    queue<pair<int, int> > data = q;
    while (!data.empty()) {
        pair<int, int> p = data.front();
        if (maxValue < p.first) {
            maxValue = p.first;
        }
        data.pop();
    }
    return maxValue;
}

int fun(int n, int m) {
    queue<pair<int, int> > q;
    int value, order = 1;
    for (int i = 0; i < n; i++) {
        cin >> value;
        q.push(make_pair(value, i));
    }

    while (!q.empty()) {
        pair<int, int> p = q.front();
        int maxValue = findMaxValue(q);

        if (p.first == maxValue) {
            // 현재 가장 맨 앞의 값이 최댓값인 경우
            if (p.second == m) {
                // 그 값이 m인 경우
                return order;
            }
            // 그 값이 m이 아닌 경우 -> 큐에서 제거
            q.pop();
            order++;
        } else {
            // 최댓값이 아니라면 재배치
            pair<int, int> p2 = q.front();
            q.pop();
            q.push(make_pair(p2.first, p2.second));
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, n, m;
    cin >> t;

    while (t--) {
        cin >> n >> m;
        cout << fun(n, m) << '\n';
    }
}
