#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

int main() {
    
    int input[5],sum=0;
    
    for(int i=0; i<5; i++){
        scanf("%d",&input[i]);
        sum += input[i];
    }
    
    printf("%d\n",sum/5);
    sort(input,input+5);
    printf("%d",input[2]);
    
    return 0;
}