#include <string>
#include <vector>

using namespace std;

vector<int> parent;
int findParent(int x){
    if(parent[x] == x)
        return x;
    return parent[x] = findParent(parent[x]);
}
void init(int n){
    parent.resize(n+1);
    for(int i=1;i<=n;i++)
        parent[i] = i;
}
void unionParent(int a, int b){
    a = findParent(a);
    b = findParent(b);
    if(a != b)
        parent[b] = a;
}
int solution(int n, vector<vector<int>> computers) {
    
    init(n);
    
    // 연결된 컴퓨터끼리 union
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i == j) continue;
            if(computers[i][j] == 1){
                unionParent(i, j);
            }
        }
    }
    
    int answer = 0;
    for(int i=0; i<n; i++){
        if(parent[i] == i)
            answer++;
    }
    
    return answer;
}