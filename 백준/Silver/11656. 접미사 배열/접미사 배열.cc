#include<iostream>
#include<set>
#include<string>
using namespace std;
set<string>s1;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string str;
    cin>>str;    
    for(int x=0;x<str.length();x++){
       string input=str.substr(x);
       s1.insert(input);      
    }
    set<string>::iterator iter=s1.begin();
	for(iter;iter!=s1.end();iter++)
		cout<<*iter<<'\n';
        
}