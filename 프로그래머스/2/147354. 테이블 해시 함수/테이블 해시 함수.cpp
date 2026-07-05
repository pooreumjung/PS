#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int index;
bool compare(const vector<int>v1, const vector<int>v2){
    if(v1[index] != v2[index])
        return v1[index] < v2[index];
    else
        return v1[0] > v2[0];
}

int func(vector<int>& v, int div){
    int answer = 0;
    
    for(int i=0; i<v.size();i++)    
        answer += v[i] % div;
        
    return answer;
}

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
    int answer = 0;
    index = col-1;
    
    sort(data.begin(), data.end(), compare);    
    
    for(int i=row_begin-1; i<=row_end-1;i++)
        answer ^= func(data[i], i+1);
    
    return answer;
}