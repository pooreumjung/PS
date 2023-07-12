#include<stdio.h>
#include<stdlib.h> 
int main(void){
    int N[100]={0,};
    int T, M, i, j;
    scanf("%d %d", &T, &M);
    for(int i = 1 ; i <= T ; i++){
        N[i]=i;
    }
    for(int t = 0 ; t < M ; t++){
        scanf("%d %d", &i, &j);
        int q = 0, tmp = 0;
        for(int y = i ; y <= (j+i)/2 ; y++){ 
            tmp = N[y];
            N[y]= N[j-q];
            N[j-q] = tmp;
            q++;
        }
    }

    for(int i = 1 ; i <= T ; i++){
        printf("%d ", N[i]);
    }
    return 0;    
}