#include<iostream>
using namespace std;
int arr[9][9];
int main(){
    int max=-1,dx=0,dy=0;
    for(int x=0;x<9;x++){
        for(int y=0;y<9;y++){
            cin>>arr[x][y];
            if(arr[x][y]>max){
                max=arr[x][y];
                dx=x;
                dy=y;
            }            
        }        
    }
    cout<<max<<endl<<dx+1<<" "<<dy+1;
    
    
}