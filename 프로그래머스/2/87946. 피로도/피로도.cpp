#include <string>
#include <vector>

using namespace std;
int answer = 0;
bool visited[8];
void func(int k, vector<vector<int>>dungeons, int count){
    answer = max(answer, count);
    
    for(int i=0;i<dungeons.size();i++){
        int need = dungeons[i][0];
        int cost = dungeons[i][1];
        
        if(!visited[i] && k>=need){
            visited[i] = true;
            func(k-cost, dungeons, count+1);
            visited[i] = false;
        }
    }
    return;
}
int solution(int k, vector<vector<int>> dungeons) {
    func(k, dungeons, 0);
    return answer;
}