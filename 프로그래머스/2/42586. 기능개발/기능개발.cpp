#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer, temp;
    // temp에 각 progresses가 며칠이 더 필요한지 계산
    for(int i =0; i<progresses.size();i++){
        int dif = 100 - progresses[i];
        if(dif % speeds[i] == 0)
            temp.push_back(dif/speeds[i]);
        else
            temp.push_back(dif/speeds[i]+1);
        cout<<temp[i]<<" ";
    }
    cout<<'\n';
    
    
    int count = 1, di = temp[0];
    for(int i=1; i<progresses.size();i++){
        if(temp[i] <= di)
            count++;
        else{
            answer.push_back(count);            
            count = 1;
            di = temp[i];
            cout<<di<<" ";
        }            
    }
    if(count > 0)
        answer.push_back(count);
    return answer;
}