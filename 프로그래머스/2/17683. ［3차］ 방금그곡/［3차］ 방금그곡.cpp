#include <string>
#include <vector>
#include <iostream>

using namespace std;

// 문자열 파싱하기
vector<string> parseString(string musicinfo){
    vector<string> v;
    string temp = "";    
    for(int i=0; i<musicinfo.length();i++){
        if(musicinfo[i] == ','){
            v.push_back(temp);
            temp = "";
        }
        else
            temp.push_back(musicinfo[i]);
    }
    v.push_back(temp);
    return v;
}

// 실행 시간 구하기
int funcTotal(string a, string b){
    
    // 각 시간이랑 분 구하기
    int hour1 = stoi(a.substr(0,2))*60;
    int hour2 = stoi(b.substr(0,2))*60;
    int minute1 = stoi(a.substr(3));
    int minute2 = stoi(b.substr(3));
    
    int total = (hour2+minute2) - (hour1+minute1);
    return total;
}

// 실행 시간만큼 돌아간 악보구하기
string funcMusicinfo(int totalTime, string musicinfo){    
    string res = "";
    int index = 0;
    
    while(totalTime--){
        if(index == musicinfo.length())
            index = 0;        
        
        res.push_back(musicinfo[index]);
        index++;                        
        
        // 다음 글자가 #인지, index가 범위를 벗어나지 않게
        if(index < musicinfo.length() && musicinfo[index] == '#'){
            res.push_back(musicinfo[index]);
            index++;                        
        }        
    }    
    return res;
}

// M찾기
bool findM(string s, string m){
    
    auto getNoteCount = [](string str){
        int cnt = 0;
        for(char c: str) if(c!='#')
            cnt++;
        return cnt;
    };
    
    int mCount = getNoteCount(m);
    string temp = "";
    
    for(int i=0; i<s.length();i++){
        temp.push_back(s[i]);
        
        if(i+1 < s.length() && s[i+1] == '#'){
            temp.push_back(s[i+1]);
            i++;
        }
        
        while(getNoteCount(temp) > mCount){
            temp.erase(0,1);
            if(!temp.empty() && temp[0] == '#')
                temp.erase(0,1);
        }
        
        if(getNoteCount(temp) == mCount)
            if(temp == m)
                return true;
    }
    
    return false;
}

string solution(string m, vector<string> musicinfos) {    
    string answer = "";
    int maxTime = 0, count=0;
        
    for(string musicinfo: musicinfos){
        
        vector<string>v = parseString(musicinfo);                
        int totalTime = funcTotal(v[0], v[1]);                
        string s = funcMusicinfo(totalTime, v[3]);         
        
        // 악보 포함하는지
        if(findM(s,m)){            
            if(totalTime > maxTime){
                answer = v[2];
                maxTime = totalTime;
            }
        }
    }
        
    if(answer.length() == 0)
        return "(None)";
            
    return answer;    
}