#include <bits/stdc++.h>
using namespace std;

priority_queue<int> pq;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, present, count;
    cin >> n >> m;

    bool check = true;
    
    for (int i = 0; i < n; i++) {
        cin >> present;
        pq.push(present);
    }

    for (int i = 0; i < m; i++) {
        cin>>count;
        if (pq.top() <count) {
            check = false;
            break;
        }
        int temp = pq.top()-count;
        pq.pop();
        if (temp>0)
            pq.push(temp);
    }

    if (check)
        cout<<1;
    else
        cout<<0;
}