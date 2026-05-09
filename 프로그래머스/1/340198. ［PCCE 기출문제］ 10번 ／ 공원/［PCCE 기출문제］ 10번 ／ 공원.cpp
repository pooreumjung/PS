#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<vector<string>>arr;
bool func(int x,int y, int n){
    int count = 0;
    for(int i=x;i<x+n;i++){
        for(int j=y;j<y+n;j++){
            if(i < arr.size() && j < arr[i].size()){
                if(arr[i][j] != "-1")
                    return false;
                else
                    count++;
            }
        }
    }
    
    if(count == n*n)
        return true;
    else
        return false;
}
int solution(vector<int> mats, vector<vector<string>> park) {
    int answer = 0;
    arr = park;
    for(int i=0;i<park.size();i++){
        for(int j=0;j<park[i].size();j++){
            if(park[i][j] == "-1"){
                for(int k=0;k<mats.size();k++){
                    int mat = mats[k];
                    if(func(i,j,mat)){
                        answer = max(answer, mat);
                        cout<<i<<" "<<j<<" "<<mat<<'\n';
                    }
                }
            }
        }
    }
    
    if(answer == 0)
        return -1;
    return answer;
}

