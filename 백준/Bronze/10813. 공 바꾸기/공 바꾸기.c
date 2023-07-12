#include <stdio.h>
int main() {
int b[100];
int N, M;
int a, c, d;
scanf("%d %d",&N,&M);
for(int i = 1; i <= N ; i++){
b[i] = i;
}
for(int i = 0; i < M ; i++){
scanf("%d %d",&a,&c);
b[d] = b[a];
b[a] = b[c];
b[c] = b[d];
}
for(int j = 1; j <= N ; j++){
printf("%d ",b[j]);
}
}