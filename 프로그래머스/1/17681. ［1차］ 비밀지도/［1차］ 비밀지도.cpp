#include <string>
#include <vector>

using namespace std;

string func(int num, int count){
    int temp = 1;
    string s ="";
    for(int i=1;i<count;i++)
        temp *=2;
    
    while(temp>0){
        int div = num/temp;
        num %= temp;
        temp/=2;
        if(div==1)
            s.push_back('#');
        else
            s.push_back(' ');
    }
    return s;
}
vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    for(int i=0;i<arr1.size();i++){
        int temp = arr1[i] | arr2[i];
        answer.push_back(func(temp,n));
    }
    return answer;
}