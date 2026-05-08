#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

char arr[4][3] = {
    {'1','2','3'},
    {'4','5','6'},
    {'7','8','9'},
    {'*','0','#'}
};
pair<int,int> findPos(int num){
    pair<int,int>temp;
    for(int i=0;i<4;i++){
        for(int j=0;j<3;j++){
            if(num == arr[i][j] -'0'){
                temp.first = i;
                temp.second = j;
                break;
            }                
        }
    }
    return temp;
}
string solution(vector<int> numbers, string hand) {
    pair<int,int> left, right;
    left = make_pair(3,0);
    right = make_pair(3,2);
    string answer = "";

    for(int i=0;i<numbers.size();i++){
        int num = numbers[i];
        pair<int,int> pos = findPos(num);   
        
        // 왼손으로 눌러야 하는 경우
        if(num == 1 || num == 4 || num == 7){
            left = make_pair(pos.first,pos.second);
            answer.push_back('L');
        }
        // 오른손으로 눌러야 하는 경우
        else if(num == 3 || num == 6 || num == 9){
            right = make_pair(pos.first,pos.second);
            answer.push_back('R');
        }
        // 가운데인 경우
        else if(num==2 || num == 5 || num == 8 || num == 0){                        
            int leftTemp = abs(pos.first-left.first) + abs(pos.second-left.second);
            int rightTemp = abs(pos.first-right.first) + abs(pos.second-right.second);
            
            if(rightTemp > leftTemp){
                left = make_pair(pos.first,pos.second);
                answer.push_back('L');
            }
            else if(leftTemp > rightTemp){
                right = make_pair(pos.first,pos.second);
                answer.push_back('R');
            }
            // 거리가 같은 경우
            else{
                cout<<leftTemp<<" "<<rightTemp<<" "<<num<<"\n";
                // 오른손잡이인 경우
                if(hand == "right"){
                    right = make_pair(pos.first,pos.second);
                    answer.push_back('R');
                }
                // 왼손잡이인 경우
                else if(hand == "left"){
                    left = make_pair(pos.first,pos.second);
                    answer.push_back('L');
                }
            }            
        }
        // cout<<arr[left.first][left.second]<<" "<<arr[right.first][right.second]<<"\n";
    }
    return answer;
}