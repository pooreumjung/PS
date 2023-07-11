#include<stdio.h>
#define MAX 9223372036854775807 //오버플로우 최대 수
int of(long long *pr,long long s){ //양수 입력시
    int r=0;
    if(*pr>MAX-s) r=1,*pr=*pr-MAX+s; //최종 res값이 MAX보다 큰 경우 처리
    else *pr+=s;
    return r; //오버플로우 발생시 1, 아니면 0
}
int uf(long long *pr,long long s){ //음수 입력시
    int r=0;
    if(*pr<-MAX-s) r=-1,*pr=*pr+MAX+s; //최종 res값이 -MAX보다 작은 경우 처리
    else *pr+=s;
    return r; //언더플로우 발생시 -1, 아니면 0 반환
}
int main(){
    int t=3;
    while(t--){
        int n,r,c=0;
        long long s,res=0;
        scanf("%d",&n);
        while(n--) {
            scanf("%lld",&s);
            r=s>0?of(&res,s):uf(&res,s); //양수, 음수(0포함) 구분 후 해당 함수 실행
            c+=r;
        }
        if(res==MAX) c++,res=0; //res가 최종적으로 MAX값일 경우 예외처리
        if(res==-MAX) c--,res=0;
        char p;
        if(c>0) p='+'; //c에 따른 출력 부호 처리
        else if(c<0) p='-';
        else {
            if(res>0) p='+'; //res에 따른 출력 부호 처리
            else if(res<0) p='-';
            else p='0';
        }
        printf("%c\n",p);
    }
    return 0;
}
