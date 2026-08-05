#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool compare(const vector<int>v1, const vector<int>v2){
    if(v1[1] != v2[1])
        return v1[1] < v2[1];
    return v1[0] < v2[0];
}
int solution(vector<vector<int>> routes) {
    int answer = 0, time;
    sort(routes.begin(), routes.end(), compare);
    
    for(int i=0;i<routes.size();i++)
        cout<<routes[i][0]<<" "<<routes[i][1]<<"\n";
    cout<<'\n';
    
    for(int i=0; i<routes.size();i++){
        if(i == 0){
            answer++;
            time = routes[i][1];
            cout<<"설치한 시간: "<<time<<'\n';
        }
        else{
            if(time < routes[i][0]){                
                answer++;
                time = routes[i][1];
                cout<<"설치한 시간: "<<time<<'\n';
            }
        }
    }
    
    return answer;
}