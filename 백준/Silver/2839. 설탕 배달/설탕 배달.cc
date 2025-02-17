#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, count1 = 50000, count2 = 50000, count3 = 0, minValue = 50000;;
    cin >> n;

    bool flag = false,flag2=false;

    // count1은 3킬로로만, count2는 5키로로만, count3은 3과 5킬로를 모두, 당연히 5키로를 우선적으로
    if (n % 3 == 0) {
        flag = true;
        count1 = n / 3;
    }

    if (n % 5 == 0) {
        flag = true;
        count2 = n / 5;
    }

    while (n >= 5) {
        count3++;
        n-=5;
        if (n % 3 == 0) {
            if (minValue > count3+n/3)
                minValue = count3+n/3;
            flag2 = true;
        }
    }


    if (!flag2)
        minValue = 50000;

    if (flag || flag2)
        cout << min(count1, min(count2, minValue));
    else
        cout << -1;
}