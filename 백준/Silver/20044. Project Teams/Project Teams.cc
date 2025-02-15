#include<bits/stdc++.h>
using namespace std;

vector<int> v;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, result = 1000000,num;
    cin >> n;

    for (int i = 0; i < 2*n; i++) {
        cin >> num;
        v.push_back(num);
    }

    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++) {
        int sum = v[i] + v[2*n-1-i];
        if (sum < result)
            result = sum;
    }

    cout << result;
}