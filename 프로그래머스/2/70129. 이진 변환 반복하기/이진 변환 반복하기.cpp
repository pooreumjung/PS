#include <string>
#include <vector>
#include <iostream>

using namespace std;


// 1의 숫자 세기
int countOne(string s){
    int count = 0;
    for(int i=0;i<s.length();i++){
        if(s[i]=='1')
            count++;
    }
    return count;
}

// 이진수 변환 함수
string func(int count) {
    if(count == 0) return "0";

    string s = "";

    while(count > 0){
        s += to_string(count % 2);
        count /= 2;
    }

    return s;
}
vector<int> solution(string s) {
    vector<int> answer(2);    
    answer[0]=0; answer[1]=0;
    
    while(true){
        int length = s.length();
        int count = countOne(s);
        answer[0]++;
        answer[1] += (length-count);
        
        if(count == 1)
            break;        
        s = func(count);                
        cout<<s<<" ";
    }
    return answer;
}