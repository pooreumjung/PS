#include <iostream>
using namespace std;
int main() {
	ios::sync_with_stdio(false), cin.tie(NULL);
    register long long N, ans = 0;
    cin >> N;
    for(register int n = 1; n * n <= N; ++n)
        ans+=1;
    cout << ans;
    return 0;
}