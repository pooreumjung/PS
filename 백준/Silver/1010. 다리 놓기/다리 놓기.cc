#include <iostream>
 
using namespace std;
 
int com(int n, int r);
int arr[31][31]={0, };
 
int main(void){
    int num;
    cin >> num;
    for(int x = 0; x < num; x++){
        int a,b;
        cin >> a >> b;
        cout << com(b, a) << endl;
    }
    
    return 0;
}
 
int com(int n,int r){
    if(arr[n][r] != 0) return arr[n][r];
    if(r == 0 || r == n) return arr[n][r] = 1;
    
    return arr[n][r] =com(n - 1, r) + com(n - 1, r - 1);
}

