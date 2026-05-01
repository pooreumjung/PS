#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 각 달에 해당하는 일수 반환
int func2(int month){
    if(month ==1 || month==3 || month==5 || month ==7 || month ==8 ||month==10 || month == 12)
        return 31;
    else if(month == 4 || month ==6 || month ==9 || month == 11)
        return 30;
    else
        return 29;
}
// 입력받은 달의 전달까지 일수합치기
int func(int a){
    if(a==1)
        return 0;
    int sum = 0;
    for(int i=1;i<=a-1;i++)
        sum += func2(i);    
    return sum;
}
string func3(int temp){
    switch(temp){
        case 0 :
            return "FRI";
            break;
        case 1 :
            return "SAT";
            break;
        case 2 :
            return "SUN";
            break;
        case 3 :
            return "MON";
            break;
        case 4 :
            return "TUE";
            break;
        case 5 :
            return "WED";
            break;
        case 6 :
            return "THU";
            break;    
    }
}
string solution(int a, int b) {
    int temp = (func(a)+b-1)%7;
    return func3(temp);
}
