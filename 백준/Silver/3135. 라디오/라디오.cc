#include<bits/stdc++.h>
using namespace std;
vector<int> v;

int findMax(int dif) {
    int num = 0, minValue = 500000;
    for (int i = 0; i < v.size(); i++) {
        if (abs(dif - v[i]) < minValue) {
            minValue = abs(dif - v[i]);
            num = v[i];
        }
    }
    return num;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    int A, B, n, value, count = 0;
    cin >> A >> B;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> value;
        v.push_back(value);
    }

    sort(v.begin(), v.end());

    int pos = findMax(B);
    count = abs(pos - B) + 1;
    cout << min(count, abs(A - B));
}