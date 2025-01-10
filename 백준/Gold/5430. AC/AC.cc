#include<bits/stdc++.h>
using namespace std;

void fun(string p, int n, string arr) {
    deque<int> dq;
    string s = "";

    
    if (n != 0) {
        // arr에서 숫자만 가져오기
        for (int i = 1; i < arr.length() - 1; i++) {
            if (arr[i] != ',') {
                s += arr[i];
            } else {
                int num = stoi(s);
                dq.push_back(num);
                s = "";
            }
        }
        dq.push_back(stoi(s));
    }
    
    bool isReversed = false;
    for (int i = 0; i < p.length(); i++) {
        if (p[i] == 'R') {
            // 뒤집기, 반복자를 맨 마지막으로
            if (isReversed) {
                isReversed = false;
            } else {
                isReversed = true;
            }
        } else if (p[i] == 'D') {
            // 버리기
            if (dq.empty()) {
                // 비어있다면 에러 출력 후 종료
                cout << "error" << "\n";
                return;
            }

            if (isReversed) // 뒤집어져 있는 상태
                dq.pop_back();

            else // 기본적인 상태
                dq.pop_front();
        }
    }

    if (!isReversed) {
        cout << "[";
        for (auto it = dq.begin(); it != dq.end(); it++) {
            cout << *it ;
            if (it != dq.end() - 1)
                cout << ",";
        }
        cout << "]" << "\n";
    } else {
        cout << "[";
        for (auto it = dq.rbegin(); it != dq.rend(); it++) {
            cout << *it;
            if (it != dq.rend() -1)
                cout << ",";
        }
        cout << "]" << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, n;
    string p, arr;

    cin >> t;
    while (t--) {
        cin >> p >> n >> arr;
        fun(p, n, arr);
    }
}
