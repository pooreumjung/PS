#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int>x1, x2, y1,y2;
vector<int> solution(vector<string> wallpapers) {
    vector<int> answer;
    for(int i=0;i<wallpapers.size();i++){
        string wallpaper = wallpapers[i];
        for(int j=0;j<wallpaper.length();j++){
            if(wallpaper[j]=='#'){
                x1.push_back(i);
                x2.push_back(i+1);
                y1.push_back(j);
                y2.push_back(j+1);
            }
        }
    }
    sort(x1.begin(),x1.end());
    sort(x2.begin(),x2.end(),greater<>());
    sort(y1.begin(),y1.end());
    sort(y2.begin(),y2.end(),greater<>());
    
    answer.push_back(x1[0]);
    answer.push_back(y1[0]);
    answer.push_back(x2[0]);    
    answer.push_back(y2[0]);
    return answer;
}