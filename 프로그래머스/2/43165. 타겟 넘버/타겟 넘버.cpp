#include <string>
#include <vector>

using namespace std;

int answer=0;
void func(vector<int>numbers, int cur,int index, int target){
    if(index == numbers.size()){
        if(cur == target)
            answer++;
        return;
    }
                  
    func(numbers, cur+numbers[index],index+1,target);
    func(numbers, cur-numbers[index],index+1, target);            
}
int solution(vector<int> numbers, int target) {    
    func(numbers, 0,0, target);
    return answer;
}