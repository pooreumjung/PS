#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, p,line,plat,ans=0;
    cin >> n >> p;

    vector A(n+1, vector<int>());

    for (int i = 0; i < n; i++) {
        cin >> line >> plat;
        while (!A[line].empty() && A[line].back() > plat)
            ans++, A[line].pop_back();
        if (!A[line].empty() && A[line].back() == plat)
            continue;
        ans++, A[line].push_back(plat);
    }
    cout << ans;
}