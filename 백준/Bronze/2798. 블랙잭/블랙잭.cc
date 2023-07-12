#include <iostream>
using namespace std;

int main() {
    int card[100];
    int n, m;
    int max;
    cin >> n >> m;

    for(int i=0; i<n; i++){
        cin >> card[i];
    }
    max = 0;

    for(int j = 0; j < (n-2); j++){
        for(int k = (j+1); k < (n - 1); k++){
            for(int l = (k+1); l < n; l++){
                if((card[j] + card[k] + card[l] <= m) && (card[j] + card[k] + card[l] > max))
                    max = card[j] + card[k] + card[l];
            }
        }
    }
    cout << max;

}