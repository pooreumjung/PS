#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0,temp=1;
    string s="";
    while(true){
        temp*=3;
        if(temp>n)
            break;
    }
    temp/=3;
    while(temp>0){
        s.push_back((n/temp)+'0');
        n%=temp;
        temp/=3;
    }
    temp=1;
    for(int i=0;i<s.length();i++){
        answer+=temp*(s[i]-'0');
        temp*=3;
    }
    
    return answer;
}

    