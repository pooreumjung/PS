#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    priority_queue<long long , vector<long long>, greater<long long>> q;
    long long num;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> num;
            if (i==0) {
                q.push(num);
            }
            else {
                q.push(num);
                q.pop();
            }
        }
    }

    cout<<q.top();
}