#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int checkedX[10], checkedY[10];
void init(string s1, string s2){
    for(int i=0;i<s1.length();i++)
        checkedX[s1[i]-'0']++;
    for(int i=0;i<s2.length();i++)
        checkedY[s2[i]-'0']++;
}
string solution(string X, string Y) {
    init(X,Y);
    vector<int>v;
    for(int i=0;i<10;i++){
        if(checkedX[i]>=1 && checkedY[i]>=1){
            for(int j=0;j<min(checkedX[i],checkedY[i]);j++)
                v.push_back(i);        
        }
    }
    
    if(v.size() == 0)
        return "-1";
    sort(v.begin(),v.end(),greater<>());
    if(v[0]==0)
        return "0";
    string answer = "";
    for(int i=0;i<v.size();i++)
        answer.push_back(v[i]+'0');
    return answer;
}