#include<iostream>
using namespace std;
int arr[1000001];
int main() {
    int t;
    cin >> t;
    for (int x = 2; x <= t; x++) {
        arr[x] = arr[x - 1] + 1;
        if (x % 3 == 0)
                arr[x] = min(arr[x], arr[x / 3] + 1);
        if (x % 2 == 0)
            arr[x] = min(arr[x], arr[x / 2] + 1);


    }
    cout << arr[t];
}