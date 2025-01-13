#include <bits/stdc++.h>
using namespace std;

vector<string> v;
map<string, int> mp;

void func2() {
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v.size(); j++) {
            if (i == j)
                continue;
            string s = v[i] + v[j];
            mp[s]++;
        }
    }
    cout << mp.size();
}

void func3() {
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v.size(); j++) {
            for (int k = 0; k < v.size(); k++) {
                if (i == j || j == k || i == k)
                    continue;
                string s = v[i] + v[j] + v[k];
                mp[s]++;
            }
        }
    }
    cout << mp.size();
}

void func4() {
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v.size(); j++) {
            for (int k = 0; k < v.size(); k++) {
                for (int l = 0; l < v.size(); l++) {
                    if (i == j || i == k || i == l || j == k || j == l || k == l)
                        continue;
                    string s = v[i] + v[j] + v[k] + v[l];
                    mp[s]++;
                }
            }
        }
    }
    cout << mp.size();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k, num;
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> num;
        v.push_back(to_string(num));
    }

    switch (k) {
        case 2:
            func2();
            break;
        case 3:
            func3();
            break;
        case 4:
            func4();
            break;
    }
}
