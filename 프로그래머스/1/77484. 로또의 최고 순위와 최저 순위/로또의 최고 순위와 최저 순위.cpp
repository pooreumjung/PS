#include <string>
#include <vector>

using namespace std;
int func(int count){    
    if(count <= 1)
        return 6;
    else if(count == 2)
        return 5;
    else if(count == 3)
        return 4;
    else if(count == 4)
        return 3;
    else if(count == 5)
        return 2;
    else
        return 1;
}

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int currectCount = 0, zeroCount = 0;
    for(int i=0;i<lottos.size();i++){
        int num = lottos[i];
        if(num == 0){
            zeroCount++;
            continue;
        }
        for(int j=0;j<win_nums.size();j++){
            if(num == win_nums[j]){
                currectCount++;
                break;
            }
        }
    }
    answer.push_back(func(currectCount+zeroCount));
    answer.push_back(func(currectCount));
    return answer;
}