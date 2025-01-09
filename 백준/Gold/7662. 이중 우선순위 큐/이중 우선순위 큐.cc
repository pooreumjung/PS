#include<bits/stdc++.h>
using namespace std;

void fun(int k) {
    map<long long, int> myMap;
    char op;
    long long n;
    for (int i = 0; i < k; i++) {
        cin >> op >> n;
        if (op == 'I') {
            auto it = myMap.find(n);
            if (it == myMap.end())
                myMap.insert({n, 1});
            else
                it->second++;
        } else {
            if (n == -1) {
                if (!myMap.empty()) {
                    auto it = myMap.begin();
                    if (it->second > 1)
                        it->second--;
                    else
                        myMap.erase(it);
                }
            } else {
                if (!myMap.empty()) {
                    auto it = myMap.rbegin();
                    if (it->second > 1)
                        it->second--;
                    else
                        myMap.erase(prev(it.base()));
                }
            }
        }
    }

    if (myMap.empty()) {
        cout << "EMPTY" << "\n";
    } else {
        cout << myMap.rbegin()->first << " " << myMap.begin()->first << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, k;
    cin >> t;

    while (t--) {
        cin >> k;
        fun(k);
    }
}