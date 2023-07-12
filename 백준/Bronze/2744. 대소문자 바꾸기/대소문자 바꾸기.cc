#include<iostream>
#include<string>
using namespace std;
int main(){
    string str;
    cin>>str;
    for(int x=0;x<str.length();x++){
        if(str[x]>64&&str[x]<97)
            cout<<(char)(str[x]+32);
        else
            cout<<(char)(str[x]-32);
           
        
    }
}