#include <iostream>
using namespace std;
long long int arr[91] = { 0,1,1 };
long long int fibo(int n) {
    if (n == 1 || n == 2)
        return 1;
    else if (arr[n] != 0)
        return arr[n];
    else {
        return arr[n] = fibo(n - 1) + fibo(n - 2);
    }

}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    cout << fibo(n);
}
