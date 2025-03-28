#include<bits/stdc++.h>
using namespace std;

int weight[2001]; // 각 차들의 무게 저장
int cash[101]; //각 주차공간의 단위 무게당 요금
map<int, int> mp; //각 차들이 주차한 곳
priority_queue<int, vector<int>, greater<int> > pq;
queue<int> waitQueue;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, num, ans = 0;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        // 주차 공간의 단위 무게당 요금 저장
        cin >> num;
        cash[i] = num;
        pq.push(i);
    }

    for (int i = 1; i <= m; i++) {
        // 각 차들의 무게 저장
        cin >> num;
        weight[i] = num;
    }

    for (int i = 0; i < 2 * m; i++) {
        cin >> num;
        // 주차장에 들어가려면 대기열이 없어야 하고 num이 양수여야 함
        if (num > 0) {
            if (!pq.empty()) {
                ans += cash[pq.top()] * weight[num];
                mp[num] = pq.top();
                pq.pop();
            } else {
                waitQueue.push(num);
            }
        } else {
            auto it = mp.find(abs(num));
            if (it != mp.end()) {
                int temp = it->second; // 나가는 주차장 번호 가져오기
                mp.erase(it); // 차의 주차기록 제거
                pq.push(temp); // 남는 주차장 우선순위 큐에 저장

                if (!waitQueue.empty()) {
                    int car = waitQueue.front(); // 주차장으로 들어가야 하는 대기열에 있는 차
                    ans += cash[pq.top()] * weight[car];
                    mp[car] = pq.top();
                    pq.pop();
                    waitQueue.pop();
                }
            }
        }
    }

    cout << ans;
}
