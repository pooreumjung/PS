#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string s) {
    int answer = 0, sameCount=0, difCount=0;
    char temp;
    for(int i=0; i<s.length();i++){
        if(i==0){
            temp = s[i];
            sameCount++;
        }
        else{
            if(difCount == 0 && sameCount == 0){
                sameCount++;
                temp = s[i];
            }
            else{
                if(s[i] == temp){
                    sameCount++;                
                }
                else
                    difCount++;
            }
        }
        if(sameCount == difCount){
            sameCount = difCount = 0;
            answer++;
        }
    }
    
    if(sameCount > 0 || difCount > 0)
        answer++;
    return answer;
}