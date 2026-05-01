#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

bool checked[4000], checked2[4000];
void init(){
    for(int i=2;i*i<=4000;i++){
        if(checked2[i])
            continue;
        for(int j=i*i;j<=4000;j+=i)
            checked2[j]=true;
    }
}
int solution(vector<int> nums) {
    int answer = 0;
    init();
    for(int i=0;i<nums.size();i++){
        for(int j=i+1;j<nums.size();j++){
            for(int k=j+1;k<nums.size();k++){
                int sum = nums[i]+nums[j]+nums[k];                
                
                if(!checked2[sum]){
                    answer++;
                    checked[sum]=true;
                }
            }
        }
    }

    return answer;
}