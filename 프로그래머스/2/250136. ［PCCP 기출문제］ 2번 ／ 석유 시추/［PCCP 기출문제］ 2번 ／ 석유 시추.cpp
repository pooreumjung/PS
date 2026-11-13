#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <set>

using namespace std;

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

vector<vector<int>> groupMap; // 각 칸이 몇 번 석유 덩어리인지 저장
vector<int> oilSize;          // 각 덩어리 번호(인덱스)별 석유량 저장

int bfs(int x, int y, int groupId, const vector<vector<int>>& land, int row, int col) {
    queue<pair<int,int>>q;
    groupMap[x][y] = groupId;
    q.push(make_pair(x,y));
    int area = 1;
    
    while(!q.empty()){
        auto cur = q.front();
        q.pop();
        
        int cx = cur.first;
        int cy = cur.second;
        
        for(int i=0; i<4; i++){
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            
            if(nx<0 || ny<0 || nx>=row || ny>= col) continue;
            if(land[nx][ny] == 0 || groupMap[nx][ny] !=0) continue;
            
            groupMap[nx][ny] = groupId;
            q.push(make_pair(nx,ny));
            area++;
        }
    }
        
    return area;
}

int solution(vector<vector<int>> land) {
    int answer = 0, row = land.size(), col = land[0].size();    
    int groupId = 1;
    
    groupMap.assign(row, vector<int>(col, 0));
    oilSize.push_back(0);
    
    for(int i=0; i<row; i++){        
        for(int j=0; j<col; j++){
            if(land[i][j] == 1 && groupMap[i][j] == 0){
                int area = bfs(i,j,groupId, land, row, col);
                oilSize.push_back(area);
                groupId++;
            }            
        }                        
    }
    
    for(int j=0; j<col; j++){
        set<int>s;
        for(int i=0; i<row; i++){
            if(groupMap[i][j] > 0)
                s.insert(groupMap[i][j]);
        }
        
        int tempArea = 0;
        for (int id : s)
            tempArea += oilSize[id];
        
        answer = max(answer, tempArea);        
    }
               
    return answer;
}