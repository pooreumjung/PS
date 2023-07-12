#include<iostream>
using namespace std;
char st[5][15];
int main(){
    for(int x=0;x<5;x++){
        cin>>st[x];
    }
    for(int y=0;y<15;y++){
        for(int x=0;x<5;x++){
            if(st[x][y]==NULL)
                continue;
            else
               cout<<st[x][y];
            
        }
        
        
    }
    
}