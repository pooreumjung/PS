#include <string>
#include <vector>
#include <map>

using namespace std;
map<int,int>mp;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int pre = 0, result=0;
    
    for(int i=0;i<progresses.size();i++){
        int diff = 100 - progresses[i];
                
        if(diff% speeds[i] == 0)
            result = diff/speeds[i];
                           
        else
            result = diff/speeds[i]+1;
        
        if(result < pre)
            mp[pre]++;
        else{
            pre = result;
            mp[pre]++;
        }                    
    }
    
    for(auto it = mp.begin(); it!=mp.end(); it++)
        answer.push_back(it->second);
    return answer;
}