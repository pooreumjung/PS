#include<bits/stdc++.h>
using namespace std;

vector<int> v;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, count = 1, index = 1;
    cin >> n >> m;
    v.resize(m + 1, 0);

    bool check = false;

    while (true) {
        for (int i = 0; i < count; i++) {
            v[index] = count;
            index++;
            if (index > m) {
                check = true;
                break;
            }
        }
        if (check)
            break;
        count++;
    }
    
    for (int i = 1; i <= m; i++) {
        v[i] = v[i - 1] + v[i];
    }

    cout << v[m] - v[n - 1];
}