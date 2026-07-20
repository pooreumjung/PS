#include <string>
#include <vector>
#include <queue>

using namespace std;

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
int answer = 0, startX, startY, endX, endY, lx, ly, row, columns;
vector<vector<int>>arr, arr2;

// 초기화 함수
void init(vector<string>maps){
    arr.resize(row, vector<int>(columns));
    arr2.resize(row, vector<int>(columns));
    // 초기화
    for(int i=0;i<arr.size();i++){
        for(int j=0;j<arr[i].size();j++){
            arr[i][j] = -1;
            arr2[i][j] = -1;
            if(maps[i][j] == 'S'){
                startX = i;
                startY = j;
            }
            else if(maps[i][j] == 'E'){
                endX = i;
                endY = j;
            }
            else if(maps[i][j] == 'L'){
                lx = i;
                ly = j;
            }
        }
    }
}

// L까지 찾아가는 함수
void dfs1(vector<string>maps){
    queue<pair<int,int>>pq;
    pq.push(make_pair(startX,startY));
    arr[startX][startY] = 0;
    
    while(!pq.empty()){
        pair<int,int>cur = pq.front();
        pq.pop();
        
        // 레버 찾으면 종료        
        if(cur.first == lx && cur.second == ly)
            break;
        
        for(int x=0;x<4;x++){
            int nx = cur.first + dx[x];
            int ny = cur.second + dy[x];
            
            if(nx <0 || ny < 0 || nx>=row || ny>=columns)
                continue;
            if(maps[nx][ny] == 'X' || arr[nx][ny] !=-1)
                continue;
                        
            arr[nx][ny] = arr[cur.first][cur.second]+1;
            pq.push(make_pair(nx,ny));            
        }
    }
}
void dfs2(vector<string>maps){
    queue<pair<int,int>>pq;
    pq.push(make_pair(lx,ly));    
    arr2[lx][ly] = 0;
    
    while(!pq.empty()){
        pair<int,int>cur = pq.front();
        pq.pop();
        
        // 레버 찾으면 종료        
        if(cur.first == endX && cur.second == endY)
            break;
        
        for(int x=0;x<4;x++){
            int nx = cur.first + dx[x];
            int ny = cur.second + dy[x];
            
            if(nx <0 || ny < 0 || nx>=row || ny>=columns)
                continue;
            if(maps[nx][ny] == 'X' || arr2[nx][ny] != -1)
                continue;
                        
            arr2[nx][ny] = arr2[cur.first][cur.second]+1;
            pq.push(make_pair(nx,ny));            
        }
    }
}
int solution(vector<string> maps) { 
    row = maps.size();
    columns = maps[0].length();
    init(maps);
    dfs1(maps);
    
    if(arr[lx][ly] == -1)
        return -1;
    
    dfs2(maps);    
    if(arr2[endX][endY] == -1)
        return -1;
    
    return arr[lx][ly]+arr2[endX][endY];
}