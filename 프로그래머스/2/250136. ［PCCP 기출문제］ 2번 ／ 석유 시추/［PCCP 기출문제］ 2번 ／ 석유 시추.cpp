#include <map>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

int rows, columns;
int dx[4] = {0,1,0,-1};
int dy[4] = {-1,0,1,0};
vector<vector<int>>arr,arr2, v;
map<int,int>mp;

void bfs(int x, int y,int count){
    arr[x][y] = 1;
    arr2[x][y] = count;
    queue<pair<int,int>>q,q2;    
    q.push(make_pair(x,y));
    q2.push(make_pair(x,y));
    int maxValue = 1, area=2;
    
    while(!q.empty()){
        pair<int,int>cur = q.front();
        q.pop();
        
        for(int i=0;i<4;i++){
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            
            if(nx <0 || ny<0 || nx>=rows || ny>=columns)
                continue;
            if(v[nx][ny] == 0 || arr[nx][ny] != -1)
                continue;
            
            arr[nx][ny] = area++;
            arr2[nx][ny] = count;
            
            q.push(make_pair(nx,ny));
            maxValue = max(maxValue, arr[nx][ny]);
        }
    }
    mp[count] = maxValue;    
}

// bfs를 전 구간에 대해서 먼저 돌리고 그 다음 탐색
int solution(vector<vector<int>>land) {
    int answer = 0, count=1;
    rows = land.size();
    columns = land[0].size();
    arr.resize(rows, vector<int>(columns, -1));
    arr2.resize(rows, vector<int>(columns, -1));
    v = land;
    
    for(int i=0;i<rows;i++){
        for(int j=0;j<columns;j++){
            // 탐색하지 않은 지점
            if(arr[i][j] == -1 && land[i][j] == 1){
                bfs(i,j,count);
                count++;
            }
        }
    }
                
    for(int i=0;i<columns;i++){
        vector<bool>temp(count+1,false);
        int value=0;
        for(int j=0;j<rows;j++){
            int area = arr2[j][i];
            if(temp[area])
                continue;
            if(area != -1){
                value += mp[area];
                temp[area] = true;
            }
        }
        answer = max(answer, value);        
    }
    
    return answer;
}