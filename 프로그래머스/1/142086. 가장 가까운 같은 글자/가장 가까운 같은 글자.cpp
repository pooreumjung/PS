#include <string>
#include <vector>

using namespace std;

int checked[26];
vector<int> solution(string s) {
    vector<int> answer;
    for(int i=0;i<26;i++)
        checked[i] = -1;
    
    for(int i=0;i<s.length();i++){
        int index = s[i]-'a';
        if(checked[index]!=-1){
            answer.push_back(i-checked[index]);
            checked[index]=i;
        }
        else{
            answer.push_back(-1);
            checked[index] = i;
        }
    }
    return answer;
}