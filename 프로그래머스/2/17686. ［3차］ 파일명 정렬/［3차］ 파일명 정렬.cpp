#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;
// 구조체 정의
struct File {
    string original;
    string head;
    int number;
    
    File(string o, string h, int n) : original(o), head(h), number(n) {}
};
vector<File> fileList;

// 소문자 변환 함수
string toLower(string s){
    for(char &c: s)
        c = tolower(c);
    return s;
}
// HEAD와 NUMBER 구하기
File func(string s){
    int index = 0;
    string name = "", num ="";
    
    while(index < s.length() && !isdigit(s[index]))
        name += s[index++];    
    while(index < s.length() && isdigit(s[index]) && num.length() < 5)
        num += s[index++];
    
    return File(s, name, stoi(num));    
}
// 비교 함수
bool compare(const File& a, const File& b){
    string h1 = toLower(a.head), h2 = toLower(b.head);
    if(h1!=h2)
        return h1 < h2;
    return a.number < b.number;
}
vector<string> solution(vector<string> files) {
    vector<string> answer;
        
    for(string s : files)
        fileList.push_back(func(s));
    
    
    stable_sort(fileList.begin(), fileList.end(), compare);
    for(auto it:fileList)        
        answer.push_back(it.original);
    
    
    return answer;
}