#include <bits/stdc++.h>
using namespace std;

// 국가 정보를 저장하는 구조체
struct Country {
    int id, gold, silver, bronze;

    // 정렬 연산자 오버로딩 (금 > 은 > 동 기준)
    bool operator<(const Country &other) const {
        if (gold != other.gold) return gold > other.gold;
        if (silver != other.silver) return silver > other.silver;
        if (bronze != other.bronze) return bronze > other.bronze;
        return false; // 동점일 경우 원래 순서 유지
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<Country> v;

    // 입력 받기
    for (int i = 0; i < n; i++) {
        int country, gold, silver, bronze;
        cin >> country >> gold >> silver >> bronze;
        v.push_back({country, gold, silver, bronze});
    }

    // 정렬 수행
    sort(v.begin(), v.end());

    // 특정 국가(K)의 등수 찾기
    int rank = 1, same=0; // 초기 등수
    for (int i = 0; i < n; i++) {
        // 동점이 아니라면
        if (i > 0 && (v[i].gold != v[i - 1].gold || v[i].silver != v[i - 1].silver || v[i].bronze != v[i - 1].bronze)) {
            rank+=same;
            same=0;
        }
        if (v[i].id == k) {
            cout << rank << "\n";
            return 0;
        }
        same++;
    }
}