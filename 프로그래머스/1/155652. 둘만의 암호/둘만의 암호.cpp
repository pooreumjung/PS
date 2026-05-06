#include <string>
#include <vector>

using namespace std;

string solution(string s, string skip, int index) {
    string answer = "";
    for(int i=0;i<s.length();i++){
        char temp = s[i];
        int j = 0;
        while(j<index){            
            temp += 1;
            if(temp > 122)
                temp = 97;
            // 존재한다면
            if(skip.find(temp) != string::npos)
                continue;
            // 존재하지 않는다면
            else
                j++;
        }
        answer.push_back(temp);
    }
    return answer;
}