#include <vector>

using namespace std;

vector<int> solution(int n) {
    vector<vector<int>> arr(n);
    
    // 초기 크기 지정
    for(int i=0;i<n;i++)
        arr[i].resize(i+1);
    
    int num = 1, x =-1, y = 0;
    
    for(int i=0; i<n;i++){
        for(int j=i; j<n;j++){
            if(i%3==0)
                x++;
            else if(i%3==1)
                y++;
            else{
                x--;
                y--;
            }
            arr[x][y] = num++;
        }
    }
    
    vector<int>answer;
    for(int i=0;i<arr.size();i++){
        for(int j=0; j<arr[i].size();j++)
            answer.push_back(arr[i][j]);
    }
    
    return answer;
}

