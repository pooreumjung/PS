#include<iostream>
#include<string>
using namespace std;
int arr[4000001];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a,b,k,cnt=0;
    cin>>a>>b>>k;
    arr[0]=1;
    arr[1]=1;
    for(int x=2;x<=4000000;x++){
        if(arr[x]==1)
            continue;
        else{
            for(int y=x*2;y<=4000000;y+=x)
                arr[y]=1;            
        }
    }
    string s=to_string(k);
    for(int x=a;x<=b;x++){
        if(arr[x]==0){
            string str=to_string(x);
            if(str.find(s)!=string::npos)
                cnt++;
        }                
    }
    cout<<cnt;
}