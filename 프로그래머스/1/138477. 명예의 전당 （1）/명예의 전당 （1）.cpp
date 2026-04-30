#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int k, vector<int> score) {
    vector<int>answer, temp;
    for(int i=0;i<score.size();i++){
        if(temp.size() < k){
            temp.push_back(score[i]);
            sort(temp.begin(), temp.end());
            answer.push_back(temp[0]);
        }
        else{            
            if(temp[0]<score[i]){
                temp.erase(temp.begin());
                temp.push_back(score[i]);
                sort(temp.begin(),temp.end());                
            }
            answer.push_back(temp[0]);
        }
    }
    return answer;
}