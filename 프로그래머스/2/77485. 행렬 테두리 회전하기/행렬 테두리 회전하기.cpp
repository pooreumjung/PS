#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    vector<vector<int>>arr(rows+1, vector<int>(columns+1));
            
    // 초기 세팅
    int number=1;
            
    for(int i=1;i<=rows;i++){
        for(int j=1;j<=columns;j++)
            arr[i][j] = number++;
    }
    
    for(int x=0;x<queries.size();x++){
        int x1 = queries[x][0], x2 = queries[x][2], y1 = queries[x][1], y2 = queries[x][3];
        int minValue = 10000000, count = 4, pre = arr[x1][y1], rotate=1;
        
        // 수행하기
        while(count--){        
            // 좌 -> 우
            // cout<<pre<<" ";
            if(rotate == 1){                
                for(int j=y1;j<y2;j++){
                    if(j+1 <=y2){          
                        int temp = arr[x1][j+1];
                        arr[x1][j+1] = pre;
                        pre = temp;
                        minValue = min(minValue, arr[x1][j+1]);
                    }
                }
                rotate = 2;
            }
            // 위 -> 아래
            else if(rotate == 2){
                for(int i=x1;i<x2;i++){
                    if(i+1 <=x2){
                        int temp = arr[i+1][y2];
                        arr[i+1][y2] = pre;
                        pre = temp;
                        minValue = min(minValue, arr[i+1][y2]);
                    }
                }
                rotate = 3;
            }
            // 우 -> 좌
            else if(rotate == 3){
                for(int j=y2; j>y1;j--){
                    if(j-1 >=y1){
                        int temp = arr[x2][j-1];
                        arr[x2][j-1] = pre;
                        pre = temp;
                        minValue = min(minValue, arr[x2][j-1]);
                    }
                }
                rotate = 4;
            }
            // 아래 -> 위
            else{
                for(int i=x2; i>x1;i--){
                    if(i-1>=x1){
                        int temp = arr[i-1][y1];
                        arr[i-1][y1] = pre;
                        pre = temp;
                        minValue = min(minValue, arr[i-1][y1]);
                    }
                }
                rotate = 1;
            }   
        }                
        answer.push_back(minValue);                                        
    }
            
    return answer;
}