#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int cnt=1;
    for(int x=0;x<n;x++){
         cnt*=2;
    }
    cnt+=1;
    cout<<(cnt*cnt);
}