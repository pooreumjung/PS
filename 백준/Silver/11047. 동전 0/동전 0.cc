#include <iostream>
#include <vector>
using namespace std;
vector<int> v;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int>v;
    for (int x = 0; x < n; x++){
        int a;
        cin >> a;
        v.push_back(a);
    }
    int result = 0;
    for (int x = n-1; x >=0; x--) {
        result += k / v[x];
        k %= v[x];
    }
    cout << result;
}
