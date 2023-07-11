#include <iostream>
using namespace std;
int  arr[10001];
int main() {
    int res = 0;
    for (int x = 1; x <= 10000; x++) {
        if (x< 10) {
            res = x + x;
            arr[res]++;
        }
        else if (x < 100) {
            res = x + (x / 10) + (x % 10);
            arr[res]++;
        }
        else if (x < 1000) {
            res = x + (x / 100) + ((x % 100) / 10) + ((x % 100) % 10);
            arr[res] ++;
        }
        else if (x < 10000) {
            res = x + (x / 1000) + ((x % 1000) / 100) + (((x % 1000) % 100) / 10) + (((x % 1000) % 100) % 10);
            if (res <= 10000)
                arr[res]++;
        }
    }

    for (int x = 1; x <= 10000; x++) {
        if (arr[x] ==0)
            cout << x << "\n";
    }
    return 0;
}