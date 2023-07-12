#include<iostream>
using namespace std;
char str[101];
int main(){
    cin>>str;
    int len=0,flag=0;
    for(int x=0;x<101;x++){
        if(str[x]=='\0')
             break;
        len=x;
    }
    for(int x=0;x<=len/2;x++){
        if(str[x]!=str[len-x]){
            flag=1;
            break;
        }  
    }
    if(flag==1)
        cout<<"0";
    
    else
        cout<<"1";
    
    
    
    
}