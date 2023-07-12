#include<iostream>
using namespace std;
int find(int a1,int a0,int c,int n){
    int flag=0;
    for(int x=n;x<=100;x++){
        if((a1*x+a0)>c*x){
            flag=1;
            break;
        }                
    }
    if(flag==1)
        return 0;
    else
        return 1;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a1,a0,c,n;     
    cin>>a1>>a0>>c>>n;
    int d=find(a1,a0,c,n);
    cout<<d;           
}