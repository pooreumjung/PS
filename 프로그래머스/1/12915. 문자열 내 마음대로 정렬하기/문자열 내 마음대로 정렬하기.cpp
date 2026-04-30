#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int index;
bool compare(const string s1, const string s2){
    if(s1[index]!=s2[index])
        return s1[index]<s2[index];
    return
        s1<s2;
}
vector<string> solution(vector<string> strings, int n) {
    index=n;
    sort(strings.begin(), strings.end(),compare);
    return strings;
}