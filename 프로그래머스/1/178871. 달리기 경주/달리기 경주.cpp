#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

unordered_map<string,int>mp;

// 초기화
void init(vector<string>players){
    for(int i=0;i<players.size();i++)
        mp[players[i]]=i;
}

vector<string> solution(vector<string> players, vector<string> callings) {
    init(players);
    vector<string> answer = players;
    for(int i=0;i<callings.size();i++){
        string name = callings[i];
        int index = mp[name];
        
        // 불린선수는 한 단계 앞으로, 그 앞의 상대는 뒤로
        mp[name] = index-1;
        mp[answer[index-1]] = index;
        swap(answer[index], answer[index-1]);        
    }
    
    return answer;
}

// mumu 