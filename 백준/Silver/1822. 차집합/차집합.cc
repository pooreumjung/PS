#include<iostream>
#include<set>
using namespace std;
set<long long int>s1;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a,b;
    cin>>a>>b;
    for(int x=0;x<a;x++){
        long long int n;
        cin>>n;
        s1.insert(n);
    }
    for(int x=0;x<b;x++){
        long long int n;
        cin>>n;
        set<long long int>::iterator it=s1.find(n);
        if(it!=s1.end())
            s1.erase(n);
    }
    if(s1.size()==0)
        cout<<"0";
    else{
        cout<<s1.size()<<'\n';
        set<long long int>::iterator iter;
        for(iter = s1.begin(); iter != s1.end(); iter++){
           cout << *iter << " " ;
        }
    }
}