#include <string>
#include <map>
#include <vector>

using namespace std;

vector<pair<string,string>> idList;
vector<string>answer;
map<string,string> nameMap; // 아이디와 이름 저장하기


// 유저 아이디는 중복 불가, 닉네임은 중복 가능
vector<string> solution(vector<string> records) {
    for(string record: records){
        // 옵션 값 구하기
        int index = record.find(' ');
        string op = record.substr(0, index);
        string right = record.substr(index+1);
                                
        // 들어오기 => 아이디랑 이름
        if(op == "Enter"){
            index = right.find(' ');
            string id = record.substr(0,index);
            string name = record.substr(index+1);
            
            // 아이디와 이름 저장 후, idList에 id 저장
            nameMap[id] = name;
            pair<string,string> cur = make_pair(id, "Enter");
            idList.push_back(cur);            
        }
        // 나가기 => id만 나옴
        else if(op == "Leave"){
            string id = record.substr(index+1); 
            pair<string,string>cur = make_pair(id, "Leave");
            idList.push_back(cur);
        }
        // 이름 바꾸기 => 아이디랑 이름
        else{
            index = right.find(' ');
            string id = record.substr(0,index);
            string name = record.substr(index+1);
            
            nameMap[id] = name;            
        }
    }
    
    for(pair<string,string>cur : idList){
        string name = nameMap[cur.first];
        if(cur.second == "Enter")
            answer.push_back(name+"님이 들어왔습니다.");
        else
            answer.push_back(name+"님이 나갔습니다.");
    }
    
    return answer;
}