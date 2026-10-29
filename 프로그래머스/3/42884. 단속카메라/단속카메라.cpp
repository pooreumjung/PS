#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(vector<int>v1, vector<int>v2){
    if(v1[1] != v2[1]) // 진출 지점에 대해서 오름차순 정렬
        return v1[1] < v2[1];
    return v1[0] < v2[0];
}
int solution(vector<vector<int>> routes) {
    int answer = 0, cur;
    sort(routes.begin(), routes.end(), compare);

    for(int i=0;i<routes.size();i++){
        if(i == 0){
            answer++;
            cur = routes[i][1];
            continue;
        }
        
        if(cur >= routes[i][0])
            continue;
        cur = routes[i][1];
        answer++;
    }
    
    return answer;
}

// -20 -15
// -18 -13
// -14 -5
// -5 -3

// -15에 설치하고, 
// -14에서는 안되니까, -5에 설치하고

