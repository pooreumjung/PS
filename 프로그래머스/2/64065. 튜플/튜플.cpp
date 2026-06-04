#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

vector<vector<int>>v;
set<int>visited;
bool compare(const vector<int>v1, const vector<int>v2){
    return v1.size() < v2.size();
}
vector<int> solution(string s) {
    string num = "";
    vector<int> answer, temp;    
    
    for(char c: s){
        if(isdigit(c))
            num += c;
        else{
            if(!num.empty()){
                temp.push_back(stoi(num));
                num = "";
            }
            
            if(c=='}' && !temp.empty()){
                v.push_back(temp);
                temp.clear();
            }
        }
    }
    
    sort(v.begin(), v.end(), compare);
    for(auto group: v){
        for(int num : group){
            if(!visited.count(num)){
                answer.push_back(num);
                visited.insert(num);
            }
        }
    }
    
    return answer;
}