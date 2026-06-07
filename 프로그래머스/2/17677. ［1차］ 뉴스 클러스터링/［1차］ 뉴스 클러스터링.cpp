#include <iostream>
#include <string>
#include <cmath>
#include <map>

using namespace std;
map<string,int>mp1, mp2;
map<string,bool>isUsed;

string toLower(string s){
    for(char &c:s)
        c = tolower(c);
    return s;
}
void func(string s, int op){
    string temp = "";
    for(int i=0;i<s.length();i++){
        if(temp.length()==2){                
            if(isalpha(temp[0]) && isalpha(temp[1])){
                temp = toLower(temp);
                if(op == 1)
                    mp1[temp]++;
                else
                    mp2[temp]++;            
                isUsed[temp] = false;
            }
            temp = temp.erase(0,1);
            i--;
        }
        else{            
            temp.push_back(s[i]);            
        }
    }
    if(temp.length()==2 && isalpha(temp[0]) && isalpha(temp[1])){
        temp = toLower(temp);
        if(op == 1)
            mp1[temp]++;
        else
            mp2[temp]++;
        isUsed[temp] = false;
    }
}
int solution(string s1, string s2) {
    int answer = 0, total=0, inter=0;             
    func(s1,1); func(s2,2);
        
    if(mp1.size() == 0 && mp2.size()==0)
        return 65536;
    
    for(auto it=mp1.begin(); it!=mp1.end();it++){ 
        auto it2 = mp2.find(it->first);
        if(it2 == mp2.end())
           total += it->second;                                                            
        else{
            total += max(it->second, it2->second);
            inter += min(it->second, it2->second);
        }        
       isUsed[it->first] = true;
    }
    
    for(auto it=mp2.begin(); it!=mp2.end();it++){        
        if(isUsed.find(it->first) -> second)
            continue;
                
        total += it->second;        
    }
        
    return floor(inter*1.0/total*65536);        
}