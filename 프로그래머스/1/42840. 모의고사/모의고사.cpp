#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int arr1[5] = {1,2,3,4,5};
int arr2[8] = {2,1,2,3,2,4,2,5};
int arr3[10] = {3,3,1,1,2,2,4,4,5,5};
bool compare(const pair<int,int>p1, const pair<int,int>p2){
    if(p1.first != p2.first)
        return p1.first > p2.first;
    return p1.second<p2.second;
}
vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int answer1=0, answer2=0, answer3=0;
    for(int i=0;i<answers.size();i++){
        int num = answers[i];
        if(num == arr1[i%5])
            answer1++;
        if(num == arr2[i%8])
            answer2++;
        if(num == arr3[i%10])
            answer3++;
    }
    vector<pair<int,int>> temp = {
        {answer1, 1},
        {answer2, 2},
        {answer3, 3}
    };
    sort(temp.begin(),temp.end(),compare);
    int max=-1;
    for(int i=0;i<temp.size();i++){
        
        if(i==0){
            max = temp[i].first;
            answer.push_back(temp[i].second);
        }
        else{
            if(temp[i].first<max)
                break;
            answer.push_back(temp[i].second);
        }
            
    }
    return answer;
}
