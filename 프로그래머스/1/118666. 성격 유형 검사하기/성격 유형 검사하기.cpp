#include <string>
#include <vector>
using namespace std;

int score[26];
char arr[4] = {'R','C','J','A'};
vector<pair<char,int>>v;
string answer="";
int func(int choice){
    if(choice == 1)
        return 3;
    else if(choice == 2)
        return 2;
    else if(choice == 3)
        return 1;
    else if(choice == 4)
        return 0;
    else if(choice == 5)
        return 1;
    else if(choice == 6)
        return 2;
    else if(choice == 7)
        return 3;
    
}
void func2(char c){
    if(c=='R'){
        if(score[c-65] >= score['T'-65])
            answer.push_back(c);
        else
            answer.push_back('T');
    }
    else if(c=='C'){
        if(score[c-65] >= score['F'-65])
            answer.push_back(c);
        else
            answer.push_back('F');
    }
    else if(c=='J'){
        if(score[c-65] >= score['M'-65])
            answer.push_back(c);
        else
            answer.push_back('M');
    }
    else{
        if(score[c-65] >= score['N'-65])
            answer.push_back(c);
        else
            answer.push_back('N');
    }
}
                             
string solution(vector<string> survey, vector<int> choices) {    
    for(int i=0;i<survey.size();i++){
        char a = survey[i][0];
        char b = survey[i][1];
        
        int choice = choices[i];
        if(choice <=3)
            score[a-65] += func(choices[i]);
        else if(choice >=4)
            score[b-65] += func(choices[i]);
        else continue;
    }
    
    for(int i=0;i<4;i++)
        func2(arr[i]);
            
    return answer;
}