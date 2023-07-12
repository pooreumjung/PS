#include <stdio.h>

char A[10000 + 2];
char B[10000 + 2];
int ans[10000 + 10];


void Reverse(char *str) {
    int i, len;
    char tmp;
    
   
    for (i = 0; ; i++) {
        if (str[i] == '\0') {
            len = i;
            break;
        }
    }
    for (i = 0; i < len/2; i++) {
        tmp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = tmp;
    }
}
int main(void)
{
    scanf(" %s %s", A, B);
    
Reverse(A);      Reverse(B);
    
    int i, sum = 0, flag = 0; 
    for (i = 0; !(A[i]=='\0' && B[i] == '\0') ; i++) {
        
        if (A[i] == '\0') A[i] = '0'; 
        if (B[i] == '\0') B[i] = '0';

        sum = A[i] - 48 + B[i] - 48 + flag; 
        if (sum >= 10) {
            ans[i] = sum - 10;
            flag = 1; 
        }
        else {
            ans[i] = sum;
            flag = 0;
        }
    }
    
    int end;
    
    if (flag) {
        ans[i] = flag;
        end = i + 1;
    }
    else end = i;
    
    for (i = end-1; i >= 0; i--) {
        printf("%d", ans[i]);
    }

    return 0;
}
