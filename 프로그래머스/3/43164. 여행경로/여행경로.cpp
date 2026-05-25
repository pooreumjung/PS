#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<string>> tickets;
vector<bool> visited;
vector<string> answer;
vector<string> path;
bool found = false;

void dfs(string cur, int useCount){
    path.push_back(cur);
    if(useCount == tickets.size()){
        answer = path;
        found = true;
        return;
    }
    
    for(int i=0;i<tickets.size();i++){
        if(visited[i]) continue;
        
        if(tickets[i][0] == cur){
            visited[i] = true;
            dfs(tickets[i][1], useCount+1);
            
            if(found)
                return;
            visited[i] = false;
        }            
    }
    path.pop_back();
        
}
vector<string> solution(vector<vector<string>> inputTickets) {

    tickets = inputTickets;
    visited.resize(tickets.size(), false);

    sort(tickets.begin(), tickets.end());
    dfs("ICN", 0);

    return answer;
}