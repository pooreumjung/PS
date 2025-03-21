#include <bits/stdc++.h>
using namespace std;

typedef struct {
    int cur_index; // 배열 내에서의 위치
    int cur_value; // 움직일 수 있는 거리
    int cur_count; // 움직인 횟수
} st;

queue<st> q;
int arr[1001];
bool visited[1001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, result = 10000;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    q.push({0, arr[0], 0});
    while (!q.empty()) {
        st temp = q.front();
        q.pop();

        if (temp.cur_index >= n - 1) {
            if (result > temp.cur_count)
                result = temp.cur_count;
            continue;
        }

        for (int i = 1; i <= temp.cur_value; i++) {
            int index = temp.cur_index + i;
            if (index < 0 || index >= n)
                continue;
            if (visited[index])
                continue;
            visited[index] = true;
            q.push({index, arr[index], temp.cur_count+1});
        }
    }

    if (result == 10000)
        cout<<-1;
    else
        cout << result;
}