#include <string>
#include <vector>
#include <iostream>

using namespace std;
string func(int cur){
    int minute = cur/100;
    int second = cur%100;
    
    string mm = minute < 10 ? "0" + to_string(minute) : to_string(minute);
    string ss = second < 10 ? "0" + to_string(second) : to_string(second);

    return mm + ":" + ss;
}

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {        
    int video = stoi(video_len.erase(2,1)), cur = stoi(pos.erase(2,1)), opStart = stoi(op_start.erase(2,1)), opEnd = stoi(op_end.erase(2,1));
    // 오프닝 구간에 속한 경우
    if(cur >= opStart && cur<=opEnd)
        cur = opEnd;
    
    for(int i=0;i<commands.size();i++){
                                                                
        // 10초 전으로 이동하기
        if(commands[i] == "prev"){
            // 현재 위치가 10초 초과인 경우
            if(cur >= 10){
                int temp = cur % 100;
                if(temp >= 10)
                    cur -= 10;
                else{
                    cur -= 50;                    
                }                
            }
            // 현재 위치가 10초 이하인 경우
            else
                cur = 0;            
        }
        
        // 10초 뒤로 이동하기
        else {                        
            int temp = cur % 100;
            if(temp >= 50){
                cur += 50;                    
            }
            else
                cur += 10;                                                        
        }
        if(cur < 0)
            cur = 0;
        else if (cur > video)
            cur = video;        
        else if(cur >= opStart && cur<=opEnd)
            cur = opEnd;
    }
    
    return func(cur);    
}