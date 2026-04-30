#include <string>
#include <algorithm>
#include <vector>

using namespace std;

string solution(vector<int> food) {
    string answer = "", temp1="",temp2="";
    for(int i=1;i<food.size();i++){
        int count = food[i];
        while(count>=2){
            count-=2;            
            temp1.push_back(i+'0');
            temp2.push_back(i+'0');                
        }
    }
    reverse(temp2.begin(), temp2.end());
    answer = temp1+"0"+temp2;
    return answer;
}