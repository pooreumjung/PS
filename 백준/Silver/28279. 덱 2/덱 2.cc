#include <bits/stdc++.h>
using namespace std;

deque<int> dq;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, op, num;
    cin >> n;

    while (n--) {
        cin >> op;
        if (op == 1) {
            cin>>num;
            dq.push_front(num);
        }
        else if (op == 2) {
            cin>>num;
            dq.push_back(num);
        }
        else if (op == 3) {
            if (dq.empty())
                cout<<-1<<'\n';
            else {
                cout<<dq.front()<<'\n';
                dq.pop_front();
            }
        }
        else if (op == 4) {
            if (dq.empty())
                cout<<-1<<'\n';
            else {
                cout<<dq.back()<<'\n';
                dq.pop_back();
            }
        }
        else if (op == 5) {
            cout<<dq.size()<<'\n';
        }
        else if (op == 6) {
            if (dq.empty())
                cout<<1<<'\n';
            else
                cout<<0<<'\n';

        }
        else if (op == 7) {
            if (dq.empty())
                cout<<-1<<'\n';
            else
                cout<<dq.front()<<'\n';
        }
        else {
            if (dq.empty())
                cout<<-1<<'\n';
            else
                cout<<dq.back()<<'\n';
        }
    }
}