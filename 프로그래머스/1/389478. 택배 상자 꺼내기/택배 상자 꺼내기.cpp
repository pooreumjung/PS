#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n, int w, int number) {
    int answer = 0, height = n /w, count=1;
    bool isEven = true;
    
    vector<vector<int>>arr(height+1, vector<int>(w));
    for(int i=height; i>=0; i--){
        if(isEven){
            for(int j=0;j<w;j++){
                if(count <= n)
                    arr[i][j] = count++;
                else
                    arr[i][j] = 0;
            }
            isEven = false;
        }
        else{
            for(int j=w-1;j>=0;j--){
                if(count <= n)
                    arr[i][j] = count++;
                else
                    arr[i][j] = 0;
            }
            isEven = true;
        }
    }
    
    // number의 좌표값 찾기
    int x, y;
    for(int i=0;i<arr.size();i++){
        for(int j=0;j<w;j++){
            if(arr[i][j] == number){
                x = i;
                y = j;
                break;
            }
        }            
    }
    
    for(int i=0;i<x;i++){
        if(arr[i][y] != 0)            
            answer++;        
    }
    
    return answer+1;
}