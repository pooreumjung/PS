#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <iostream>

using namespace std;

string gather = "AEIOU";
set<string>mySet;

void init(){
    string temp = "";
    for(int i=0;i<5;i++){
        temp = {gather[i]};
        mySet.insert(temp);
        for(int j=0;j<5;j++){
            temp = {gather[i],gather[j]};
            mySet.insert(temp);
            for(int k=0;k<5;k++){
                temp = {gather[i],gather[j],gather[k]};
                mySet.insert(temp);
                for(int x=0;x<5;x++){
                    temp = {gather[i],gather[j],gather[k],gather[x]};
                    mySet.insert(temp);
                    for(int y=0;y<5;y++){
                        temp = {gather[i],gather[j],gather[k],gather[x],gather[y]};
                        mySet.insert(temp);
                    }
                }
            }
        }
    }
}
int solution(string word) {
    init();
    int answer = 1;
    
    for(auto it=mySet.begin(); it!=mySet.end();it++){        
        if(*it == word)
            break;
        answer++;
    }
    
    
    return answer;
}