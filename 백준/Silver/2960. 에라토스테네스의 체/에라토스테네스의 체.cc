#include <iostream>
#include<vector>

using namespace std;
vector<bool> numArr;
int n, cnt=0,k;

int solve(int n, int k) {
    int min = 2;
    numArr.resize(n + 1, 1);   //n을 하나크게 만들어서 0
    for (int i = 2; i <=n; i++) {
        for(int j = i;j<=n;j+=i){
            if (numArr[j]) {
                numArr[j] = 0;
                cnt++;
                if (cnt == k)
                    return j;
            }
        }
    }
    return 0;
}
int main()
{
    cin >> n >> k;
    cout << solve(n, k);
    return 0;
}