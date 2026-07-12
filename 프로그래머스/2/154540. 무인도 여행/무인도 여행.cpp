#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;
queue<pair<int,int>>q;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};
int rowSize, colSize;
bool visited[101][101];

int bfs(int i,int j, vector<string>maps){
    
    visited[i][j] = true;
    int area = maps[i][j]-'0';    
    q.push(make_pair(i,j));
    
    while(!q.empty()){
        pair<int,int>cur = q.front();
        q.pop();
        
        for(int i=0;i<4;i++){
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            
            if(nx<0 || ny<0 || nx>= rowSize || ny>=colSize)
                continue;
            if(visited[nx][ny] || maps[nx][ny] == 'X')
                continue;
            
            q.push(make_pair(nx,ny)); 
            area += maps[nx][ny]-'0';                        
            visited[nx][ny] = true;
        }
    }
    
    return area;
}

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    rowSize = maps.size(), colSize = maps[0].length();
                            
    for(int i=0;i<rowSize;i++){
        for(int j=0;j<colSize;j++){
            if(maps[i][j] == 'X')
                continue;
            if(visited[i][j])
                continue;
            
            int area = bfs(i,j,maps);
            answer.push_back(area);            
        }
        
    }
    
    if(answer.size() == 0)
        answer.push_back(-1);
    else
        sort(answer.begin(), answer.end());
    
    return answer;
}