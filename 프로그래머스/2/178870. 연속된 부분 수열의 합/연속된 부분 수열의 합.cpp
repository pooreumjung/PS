#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
    int left =0, right = 0, length=0, sum=0, minLength=10000011,index1=0, index2=0;
    while(true){
        if(left >= sequence.size())
            break;
        // 작은 경우는 더해주기
        if(sum < k ){
            if(right >= sequence.size())
                break;
            sum += sequence[right];
            right++;
            length++;
        }
        // 큰 경우는 빼주기
        else if(sum > k){
            sum -= sequence[left];
            left++;
            length--;
        }
        // 같으면 비교 후 빼주기
        else{            
            if(minLength > length){
                minLength = length;                
                index1 = left;
                index2 = right-1;                
            }
            sum -= sequence[left];
            left++;
            length--;
        }
    }
    answer.push_back(index1);
    answer.push_back(index2);
    return answer;
}