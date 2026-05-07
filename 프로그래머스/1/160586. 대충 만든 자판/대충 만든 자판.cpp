#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    for(int i=0;i<targets.size();i++){
        // 각 문자열
        string s = targets[i]; 
        int count = 0;
        bool possible = true;
        for(int j=0;j<s.length();j++){
            int minIndex = 150;
            for(int k=0;k<keymap.size();k++){
                size_t tempIndex= keymap[k].find(s[j]);
                if(tempIndex!=string::npos)
                    minIndex = min(minIndex, (int)tempIndex);
            }
            if(minIndex == 150){
                possible = false;
                break;
            }                
            else
                count += minIndex+1;            
        }
        if(!possible)
            answer.push_back(-1);
        else
            answer.push_back(count);
    }
    return answer;
}