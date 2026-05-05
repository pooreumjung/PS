#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string sortBy="";
bool compare(const vector<int>v1, const vector<int>v2){
    if(sortBy == "code"){
        return v1[0]<v2[0];
    }
    else if(sortBy == "date"){
        return v1[1]<v2[1];
    }
    else if(sortBy == "maximum"){
        return v1[2]<v2[2];
    }
    else if(sortBy == "remain"){
        return v1[3]<v2[3];
    }
}
vector<vector<int>> func(vector<vector<int>> data, string ext, int val_ext){
    vector<vector<int>>answer;
    if(ext == "code"){
        for(int i=0;i<data.size();i++){
            if(data[i][0]<val_ext)
                answer.push_back(data[i]);
        }
    }
    else if(ext == "date"){
        for(int i=0;i<data.size();i++){
            if(data[i][1]<val_ext)
                answer.push_back(data[i]);
        }
    }
    else if(ext == "maximum"){
        for(int i=0;i<data.size();i++){
            if(data[i][2]<val_ext)
                answer.push_back(data[i]);
        }
    }
    else if(ext == "remain"){
        for(int i=0;i<data.size();i++){
            if(data[i][3]<val_ext)
                answer.push_back(data[i]);
        }
    }
    return answer;
}

vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by) {
    vector<vector<int>> answer;
    sortBy = sort_by;
    
    // 데이터 가공 및 정렬
    answer = func(data, ext, val_ext);   
    sort(answer.begin(), answer.end(), compare);
    
    return answer;
}