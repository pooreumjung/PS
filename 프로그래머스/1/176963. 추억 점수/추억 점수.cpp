#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    for(vector<string>v:photo){
        int sum = 0;
        for(int i=0;i<name.size();i++){
            string s = name[i];
            auto it = find(v.begin(),v.end(),s);
            if(it!=v.end()){                
                sum+=yearning[i];
            }
        } 
        answer.push_back(sum);
    }
    return answer;
}