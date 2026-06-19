#include <string>
#include <vector>

using namespace std;

vector<vector<int>>arr;
vector<int> answer(2);

void func(int x,int y, int size){
    
    int start = arr[x][y];
    bool isSame = true;
    
    for(int i = x; i<x+size;i++){
        for(int j = y; j<y+size;j++){
            if(start != arr[i][j]){
                isSame = false;
                break;
            }                
        }
    }
    
    if(isSame){
        answer[start]++;
        return;
    }
    
    size /= 2;
    
    func(x,y,size);
    func(x+size,y,size);
    func(x,y+size,size);
    func(x+size,y+size,size);
}

vector<int> solution(vector<vector<int>> temp) {
    arr = temp;
    func(0,0,temp.size());
    return answer;
}