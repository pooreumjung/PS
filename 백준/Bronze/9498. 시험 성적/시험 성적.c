#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    
    for(int i = 1 ; 1; i++){
    
    if(n>=60){
    if(90<=n){printf("A"); break;}
    if(80<=n){printf("B"); break;}
    if(70<=n){printf("C"); break;}
    if(60<=n){printf("D"); break;}
    } else {printf("F"); break;}
  
    }
}
