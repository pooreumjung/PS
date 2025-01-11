#include<bits/stdc++.h>
using namespace std;

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
            dq.pop_front();
            return cal;
        }
        
        int pos2 = findValuePos(pos); 
        int size = dq.size(); 
        if (((size/2)+1 == pos2 && size % 2 == 1) || (size / 2 >= pos2 ))  {

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
        cal += fun(q.front());
        q.pop();
    }
    cout << cal;
}