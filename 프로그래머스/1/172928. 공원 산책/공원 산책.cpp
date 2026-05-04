#include <string>
#include <vector>
#include <iostream>

using namespace std;
pair<int,int>cur;
vector<string>arr;

void func(char di, int move){
    int x = cur.first;
    int y = cur.second;
    cout<<di<<" "<<move<<" ";
    // 동쪽
    if(di=='E'){
        for(int i=1;i<=move;i++){
            y += 1;
            if(y >= arr[x].length())
                return;
            if(arr[x][y]=='X')
                return;
        }
    }
    // 남쪽
    else if(di=='S'){
        for(int i=1;i<=move;i++){
            x +=1;
            if(x >= arr.size())
                return;
            if(arr[x][y]=='X')
                return;
        }        
    }
    // 서쪽
    else if(di=='W'){
        for(int i=1;i<=move;i++){
            y -=1;
            if(y < 0)
                return;
            if(arr[x][y]=='X')
                return;
        }        
    }
    // 북쪽
    else{
        for(int i=1;i<=move;i++){
            x -=1;
            if(x < 0)
                return;
            if(arr[x][y]=='X')
                return;
        }        
    }
    cur.first = x;
    cur.second = y;
}
vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    arr = park;
    // 시작점 찾기
    for(int i=0;i<park.size();i++){
        for(int j=0;j<park[i].length();j++){
            if(park[i][j]=='S'){
                cur.first = i;
                cur.second = j;                
                break;
            }
        }
    }
    
    // 라우트 탐색
    for(int i=0;i<routes.size();i++){
        string s = routes[i];
        char di = s[0];
        int move = s[2]-'0';
        func(di, move);
        cout<<cur.first<<" "<<cur.second<<"\n";
    }
    answer.push_back(cur.first);
    answer.push_back(cur.second);
    return answer;
}