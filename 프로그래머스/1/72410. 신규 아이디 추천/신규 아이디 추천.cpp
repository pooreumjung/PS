#include <string>
#include <vector>
#include <cctype>
#include <iostream>

using namespace std;

// 1단계 => 대문자를 소문자로 변환 
string func1(string s){
    for(int i=0;i<s.length();i++){
        if(isupper(s[i]))
            s[i] = tolower(s[i]);
    }
    return s;
}
// 2단계 => 필요한 문자들만 찾기
string func2(string s){
    string temp="";
    for(int i=0;i<s.length();i++){
        char c = s[i];
        if(islower(c) || c == '-' || c == '_' || c == '.' || isdigit(c))
            temp.push_back(c);
    }
    return temp;
}
// 3단계 => 연속된 마침표 한 개로 변경
string func3(string s){
    string temp="";
    int index = 0;
    while(index < s.length()){
        char c = s[index];
        if(c=='.'){
            int j = index+1;
            int count = 1;
            while(j < s.length()){
                if(s[j]!='.')
                    break;
                count++;
                j++;
            }
            index = j;            
        }
        else{            
            index++;
        }
        temp.push_back(c);
    }
    return temp;
}
// 4단계 => 처음과 끝인 마침표 제거하기
string func4(string s){

    if(s[0] == '.'){
        while(s.length() && s[0] == '.')
            s.erase(s.begin());        
    }

    if(s[s.length()-1] == '.'){
        while(s.length() && s[s.length()-1] == '.')
            s.erase(s.end()-1);        
    }        
     
    return s;
}
// 5단계 함수
string func5(string s){
    if(s.length()==0)
        return "a";
    else
        return s;
}
// 6단계 함수
string func6(string s){
    if(s.length()>=16){
        s = s.substr(0, 15);
        if(s[s.length()-1] == '.'){
            while(s.length() && s[s.length()-1] == '.')
            s.erase(s.end()-1);
        }
            
        return s;
    }
    else
        return s;
}
string func7(string s){
    if(s.length()<=2){
        char c = s[s.length()-1];
        while(s.length()<3)
            s.push_back(c);
        return s;
    }
    else
        return s;
}
string solution(string new_id) {
    
    string answer = func1(new_id);
    cout<<answer<<'\n';
    
    answer = func2(answer);
    cout<<answer<<'\n';
    
    answer = func3(answer);
    cout<<answer<<'\n';
    
    answer = func4(answer);
    cout<<answer<<'\n';
    
    answer = func5(answer);
    cout<<answer<<'\n';
    
    answer = func6(answer);
    cout<<answer<<'\n';
    
    answer = func7(answer);   
    cout<<answer<<'\n';
    
    return answer;
}

// 1. 모든 대문자 -> 소문자
// 2. 알파벳 소문자, 숫자, 빼기, 밑줄, 마침표만 가능
// 3. 마침표가 2개 이상이면 한 개로
// 4. 마침표가 처음이나 끝이면 제거
// 5. 빈 문자열이면 a로
// 6. 16자 이상이면, 앞의 15개만 남김, 그리고 .이 마지막에 남으면 .제거
// 7. 2자 이하면, 마지막 문자를 3이될때까지 계속 붙임