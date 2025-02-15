#include<bits/stdc++.h>
using namespace std;

vector<pair<int, int> > v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, minPackage = 10000, minPeace = 10000, sum1 = 0, sum2=0, sum3=0;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        if (a < minPackage) minPackage = a;
        if (b < minPeace) minPeace = b;
        v.push_back({a, b});
    }

    // 경우의 수 나누기
    // 1. 패키지 + 낱개
    // 2. 패키지로만
    // 3. 낱개로만

    sum1 += minPackage*(n/6) + minPeace * (n%6);
    sum2 += minPackage*(n/6 + 1);
    sum3 += minPeace * (n);

    cout<<min(min(sum1, sum2), sum3);

}