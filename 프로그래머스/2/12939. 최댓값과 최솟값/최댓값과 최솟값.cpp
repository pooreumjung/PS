#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int>v;
string solution(string s) {
    
    string answer = "",temp="";
    int start=0, end=0;
    
    while((end=s.find(' ',start)) != string::npos){
        temp = s.substr(start, end-start);        
        start = end +1;
        v.push_back(stoi(temp));     
    }
            
    temp = s.substr(start);
    v.push_back(stoi(temp));
    
    for(int i=0;i<v.size();i++)
        cout<<v[i]<<" ";
    
    sort(v.begin(), v.end());
    answer += to_string(v[0])+" ";
    answer += to_string(v[v.size()-1]);
    
    return answer;
}