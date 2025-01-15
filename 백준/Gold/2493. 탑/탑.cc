#include <bits/stdc++.h>
using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,tower;
    cin >> n;

    stack<pair<int,int>>s;

    for (int i = 1; i <= n; i++) {
        cin >> tower;

        while (!s.empty()) {
            if (s.top().second > tower) {
                cout<<s.top().first<<" ";
                break;
            }
            s.pop();
        }

        if (s.empty())
            cout<<0<<" ";

        s.push({i,tower});
    }
}