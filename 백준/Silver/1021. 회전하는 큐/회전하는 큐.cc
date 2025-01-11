#include<bits/stdc++.h>
using namespace std;

// deque를 통해 위치를 지정하고
// queue를 통해 입려값을 받고
// find함수를 만든다


queue<int> q;
deque<int> dq;

int findValuePos(int target) {
    int pos = 1;
    for (auto it = dq.begin(); it != dq.end(); it++) {
        if (*it == target)
            return pos;
        pos++;
    }
}

int fun(int pos) {
    int cal = 0;
    while (!dq.empty()) {
        if (pos == dq.front()) {
            // pos와 dq.front()가 같다면 종료
            dq.pop_front();
            return cal;
        }

        // 맨 첫값이 뽑을려는 위치가 아닐 때
        int pos2 = findValuePos(pos); // 먼저 위치를 구함
        int size = dq.size(); // deque의 사이즈를 구함
        if (((size/2)+1 == pos2 && size % 2 == 1) || (size / 2 >= pos2 ))  {
            // deque의 길이가 짝수일 때
            // 뽑을려는 원소의 위치가 deque의 중간보다 왼쪽에 있다
            while (true) {
                if (pos == dq.front()) {
                    dq.pop_front();
                    return cal;
                }
                int num = dq.front();
                dq.pop_front();
                dq.push_back(num);
                cal++;
            }
        }

        // 뽑을려는 위치가 deque의 오른쪽보다 있다.
        while (true) {
            if (pos == dq.front()) {
                dq.pop_front();
                return cal;
            }
            int num = dq.back();
            dq.pop_back();
            dq.push_front(num);
            cal++;
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, pos, cal = 0;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        cin >> pos;
        q.push(pos);
    }

    for (int i = 0; i < n; i++) {
        dq.push_back(i + 1);
    }


    while (!q.empty()) {
        // int res =  fun(q.front());
        // q.pop();
        // for (auto it = dq.begin(); it != dq.end(); it++) {
        //     cout << *it << " ";
        // }
        // cout<<res<<endl;
        cal += fun(q.front());
        q.pop();
    }

    cout << cal;
}


// 1을 찾고 나서 => 2 3 4 5 6 7 8 9 10 : 0번
// 6을 찾고 나서 => 7 8 9 10 2 3 4 5 : 4번
// 3을 찾고 나서 => 4 5 7 8 9 10 2 : 3번
// 2를 찾고 나서 => 4 5 7 8 9 10 : 1번
// 7을 찾고 나서 => 8 9 10 4 5 : 2번
// 9를 찾고 나서 => 10 4 5 8 : 1번
// 8을 찾고 나서 => 10 4 5 : 1번
// 4를 찾고 나서 => 10 5 : 1번
// 10을 찾고 나서 => 5 : 0번
// 5를ㄹ 찾고 나서 => 0 : 0반