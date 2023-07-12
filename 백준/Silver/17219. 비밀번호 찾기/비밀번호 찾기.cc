#include<iostream>
#include<string>
#include<map>
#include<algorithm>
using namespace std;
map<string,string>v1;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);   
    int n,m;
    cin>>n>>m;
    for(int x=0;x<n;x++){
        string s1,s2;
        cin>>s1>>s2;
        v1.insert({s1,s2});
    }
    for(int x=0;x<m;x++){
        string str;
        cin>>str;
        cout<<v1[str]<<'\n';                               
    }        
}