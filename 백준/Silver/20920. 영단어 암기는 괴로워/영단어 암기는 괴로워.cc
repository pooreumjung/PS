#include <bits/stdc++.h>
using namespace std;

map<string, int> mp;

// customSort 함수 수정
bool customSort(const pair<string, int> &a, const pair<string, int> &b) {
    if (a.second != b.second) { // 가장 자주 나오는 값을 기준
        return a.second > b.second;
    }
    if (a.first.size() != b.first.size()) { // 단어의 길이순
        return a.first.size() > b.first.size();
    }
    return a.first < b.first; // 사전순 (오름차순)
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if (mp.find(s) == mp.end()) {
            mp.insert({s, 1});
        } else {
            mp[s] += 1;
        }
    }

    // map 데이터를 vector로 변환
    vector<pair<string, int>> v(mp.begin(), mp.end());
    // customSort를 사용해 정렬
    sort(v.begin(), v.end(), customSort);

    for (int i = 0; i < v.size(); i++) {
        if (v[i].first.length()>=m)
            cout<<v[i].first<<'\n';
    }
}