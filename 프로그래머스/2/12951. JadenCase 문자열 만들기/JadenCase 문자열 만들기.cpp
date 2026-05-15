#include <string>
#include <vector>
#include <iostream>

using namespace std;
string func(string s){
    string temp = "";
    for(int i=0;i<s.length();i++){
        if(i==0 && isalpha(s[i]))
            s[i] = toupper(s[i]);
        else if(i>0 && isalpha(s[i]))
            s[i] = tolower(s[i]);            
    }
    return s;
}

string solution(string s) {
    string answer = "", temp="";
    int start=0, end=0;
    
    while((end = s.find(' ',start)) !=string::npos){
        temp = s.substr(start, end-start);        
        answer=answer+(func(temp))+" ";        
        start = end+1;
    }
    
    temp = s.substr(start);
    answer+=func(temp);
    
    return answer;
}