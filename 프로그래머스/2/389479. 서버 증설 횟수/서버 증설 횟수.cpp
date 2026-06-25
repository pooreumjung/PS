#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;
queue<pair<int,int>>q;
// m명당 서버 1대, m명 미만이면 서버 
// 시간대에 n*m<= x < (n+1)*m => n대 서버
// 한 번 증설 => k시간

// 현재 시간대에 켜져 있는 서버 개수 반환 + 지난 서버 탈락
int validateServer(int time){
    
    while(!q.empty()){
        pair<int,int>cur = q.front();                

        if(time >= cur.second)
            q.pop();
                
        else
            break;            
    }
    
    return q.size();
}

int solution(vector<int> players, int m, int k) {
    int answer = 0, currentServerCount=0;
    
    for(int i=0; i<players.size();i++){
        // 만료된 서버들이 있는지 검사
        currentServerCount = validateServer(i);
        int currentPlayer = players[i];
        
        // 사용자 수가 m이상인 경우 => 서버를 증설함
        if(currentPlayer >= m){
            int needServerCount = currentPlayer / m;
            if(needServerCount > currentServerCount){
                int diff = needServerCount - currentServerCount;
                answer += diff;
                for(int j=0;j<diff;j++)
                    q.push(make_pair(i,i+k));
                cout<<i<<" "<<needServerCount<<" "<<currentServerCount<<" "<<answer<<'\n';
            }
        }
        
    }
    
    return answer;
}



