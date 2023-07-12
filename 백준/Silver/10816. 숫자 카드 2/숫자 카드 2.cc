#include<iostream>
using namespace std;
int arr[20000002];
int main(){
    int n;
    scanf("%d",&n);
    for(int x=0;x<n;x++){
        int a;
        scanf("%d",&a);
        arr[a+10000000]+=1;
    }
    int nb;
    scanf("%d",&nb);
    for(int x=0;x<nb;x++){
        int d;
        scanf("%d",&d);
        printf("%d ",arr[d+10000000]);                  
    }    
}