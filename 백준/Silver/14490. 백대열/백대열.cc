#include<iostream>
using namespace std;
int find(int a,int b){
    if(b==0)
        return a;
    else
        return find(b,a%b);   
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a,b,res=0;
    char c;
    cin>>a>>c>>b;
    if(a>b)
         res=find(a,b);
    else
         res=find(b,a);
    cout<<(a/res)<<":"<<(b/res);
}