#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    multiset<long long> s;
    long long num;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> num;
            if (i==0) {
                s.insert(num);
            }
            else {
                s.insert(num);
                const auto it = s.begin();
                s.erase(it);
            }
        }
    }

    auto it = s.begin();
    cout<<*it;

}