#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

unordered_map<string,int>mp;
string solution(vector<string> participant, vector<string> completion) {
    
    for(int i=0;i<participant.size();i++)
        mp[participant[i]]++;
    
    for(int i=0;i<completion.size();i++){
        string temp = completion[i];
        auto it = mp.find(temp);
        if(it->second > 0)
            it->second--;
    }
    
    for(auto &it:mp){
        if(it.second > 0)
            return it.first;
    }
    return "";
}