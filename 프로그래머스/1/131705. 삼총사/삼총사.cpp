#include <string>
#include <vector>

using namespace std;

int solution(vector<int> number) {
    int answer = 0,size=number.size();
    for(int i=0;i<size;i++){
        for(int j=i+1;j<size;j++){
            for(int k=j+1;k<size;k++){
                int temp = number[i]+number[j]+number[k];
                if(temp==0)
                    answer++;
            }
        }
    }
    return answer;
}