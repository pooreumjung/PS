#include <iostream>
#include <math.h>
#define MAX 1000001             

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);     
    cin.tie(nullptr);
    cout.tie(nullptr);

    int prime[MAX] = { 1, };        

    for (int x = 2; x <= sqrt(MAX); x++) {      
        if (prime[x] != 0)
            continue;
        for (int y = x * x; y <= MAX; y += x) {
            prime[y] = 1;
        }
    }

    int n;
    while (1) {
        cin >> n;
        if (n == 0)
            break;
        bool find = false;  
        for (int x = 2; x < n; x++) {
            if (prime[x] == 0 && prime[n - x] == 0) {      
                cout << n << " = " << x << " + " << n - x << '\n';
                find = true;
                break;
            }
        }
        
        }
    }
   
