#include <bits/stdc++.h>
using namespace std;

map<int, set<int>> mp;
map<int,int> resultMp;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, p,line,plat,result=0;
    cin >> n >> p;

    for (int i = 0; i < n; i++) {
        cin >> line >> plat;

        auto& lineSet = mp[line];

        // 이미 누르고 있는 플랫보다 높은 것들은 떼기
        while (!lineSet.empty() && *lineSet.rbegin() > plat) {
            lineSet.erase(*lineSet.rbegin());
            resultMp[line]++;
        }

        // plat이 아직 눌리지 않았다면 누르기
        if (!lineSet.count(plat)) {
            lineSet.insert(plat);
            resultMp[line]++;
        }
    }

    for (auto it= resultMp.begin(); it != resultMp.end(); it++) {
        result+=it->second;
    }
    cout << result << endl;
}