#include <vector>
#include <set>

using namespace std;

vector<vector<int>>arr;
vector<int>selected;
vector<set<int>>q2;

// 백트래킹 
void dfs(int start, int number){
    if(selected.size() == 5){
        arr.push_back(selected);
        return;
    }
    
    for(int i=start; i<=number; i++){
        selected.push_back(i);
        dfs(i+1, number);
        selected.pop_back();
    }
}

bool func(vector<int>v,vector<int>ans){
    for(int i=0;i<q2.size();i++){
        set<int>s = q2[i];
        int count = 0;
        
        // 각각의 조합에 대해서 ans개수와 같은지 비교
        for(int j=0;j<v.size();j++){
            if(s.find(v[j])!=s.end())
                count++;
        }
        
        if(count != ans[i])
            return false;
    }
    
    return true;
}

int solution(int n, vector<vector<int>> q, vector<int> ans) {
    int answer = 0;
        
    // 우선 O(log n)으로 찾기 위해서 vector<set>으로 이관
    for(int i=0;i<q.size();i++){
        vector<int> temp = q[i];
        set<int>s;
        for(int j=0;j<temp.size();j++)
            s.insert(temp[j]);
        q2.push_back(s);
    }
    
    // 1부터 n까지의 5가지 조합을 생성하는 백트래킹
    dfs(1, n);
    
    // 만들어진 조합들에 대해서 검사
    for(vector<int>v: arr){
        if(func(v,ans))
            answer++;
    }
    
    return answer;
}