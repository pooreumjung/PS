#include <string>
#include <vector>
#include <cctype>

using namespace std;

string solution(string s) {
    string answer = "",temp="";
    int lastIndex;
    for(int i=0;i<s.length();i++){
        if(s[i]==' '){
            for(int j=0;j<temp.length();j++){
                if(j%2==0)
                    answer.push_back(toupper(temp[j]));
                else
                    answer.push_back(tolower(temp[j]));
            }
            answer.push_back(s[i]);
            temp="";
        }
        else{
            temp.push_back(s[i]);
        }
    }
    for(int j=0;j<temp.length();j++){
                if(j%2==0)
                    answer.push_back(toupper(temp[j]));
                else
                    answer.push_back(tolower(temp[j]));
            }
    return answer;
}