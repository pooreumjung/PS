#include<bits/stdc++.h>
using namespace std;

// 구조체 정의
struct Country {
    int id; // 국가 ID
    int gold; // 금메달 개수
    int silver; // 은메달 개수
    int bronze; // 동메달 개수

    // 정렬 연산자 오버로딩
    bool operator<(const Country &other) const {
        if (gold != other.gold) return gold > other.gold; // 금메달 우선 정렬
        if (silver != other.silver) return silver > other.silver; // 은메달 정렬
        if (bronze != other.bronze) return bronze > other.bronze; // 동메달 정렬
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<Country> v;
    map<int,int>mp;

    for (int i = 0; i < n; i++) {
        int country, gold, silver, bronze;
        cin >> country >> gold >> silver >> bronze;
        v.push_back({country, gold, silver, bronze});
    }

    // 정렬
    sort(v.begin(), v.end());
    int rank=1;
    for (int i=0; i<v.size();i++) {
        if (i==0)
            mp.insert({v[i].id, rank});
        else {
            if (v[i-1].gold == v[i].gold && v[i-1].silver == v[i].silver && v[i-1].bronze == v[i].bronze) {
                mp.insert({v[i].id, rank-1});
            }
            else
                mp.insert({v[i].id, rank});
        }
        rank++;
    }

    cout<<mp.find(k)->second;
}