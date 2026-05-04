#include <string>
#include <vector>
#include <iostream>

using namespace std;
int sat, sun;
void init(int startday){
    if(startday<=6){
        sat = 6-startday;
        sun = 7-startday;
    }
    else {
        sat = 6;
        sun = 0;
    }
    
}

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int answer = 0;
    init(startday);
    // 초기값 세팅
    for(int i=0;i<schedules.size();i++){
        int temp = schedules[i]+10;
        int hour = temp/100, minute=temp%100;
        if(minute>=60){
            minute -= 60;
            hour +=1;
            temp = hour*100+minute;
        }
        schedules[i]=temp;
        cout<<schedules[i]<<" ";
    }
    cout<<"\n";
    
    for(int i=0;i<timelogs.size();i++){
        bool possible = true;
        for(int j=0;j<timelogs[i].size();j++){
            if(j==sat || j==sun)
                continue;
            if(timelogs[i][j]>schedules[i]){
                possible = false;
                break;
            }
        }
        cout<<i<<" "<<possible<<'\n';
        if(possible)
            answer++;
    }
    return answer;
}