#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> diffs, times;
int size = 0;
long long func(int level, long long limit){
    long long total=0;
    
    for(int i=0;i<times.size();i++){
        int diff = diffs[i];
        if(level >= diff)
            total += times[i];
        else{
            int temp = 0;
            for(int j=i-1;j<=i;j++)
                temp += times[j];
            total += temp*(diff-level) + times[i];
        }        
    }
    
    return total;
}

int solution(vector<int> diffArr, vector<int> timeArr, long long limit) {
    diffs = diffArr;
    times = timeArr;
    sort(diffArr.begin(), diffArr.end());
    int answer = 10000000, size = diffArr.size();
    int left = diffArr[0], right = diffArr[size-1];
            
    while(left <= right){
        int mid = (left + right) /2;
        long long total = func(mid, limit);
        
        // 넘어 가는 경우, level을 키운다
        if(total > limit){
            left = mid+1;
        }
        // 이하인 경우에는 level을 줄인다
        else{
            answer = min(answer, mid);
            right = mid -1;
        }
        cout<<total<<" ";
    }
    
    return answer;
}

