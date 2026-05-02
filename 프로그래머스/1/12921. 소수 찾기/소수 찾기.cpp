#include <string>
#include <vector>

using namespace std;

bool checked[1000001];
void init(int n){
    for(int i=2;i*i<=n;i++){
        if(checked[i])
            continue;
        for(int j=i*i;j<=n;j+=i)
            checked[j]=true;
    }
}
int solution(int n) {
    init(n);
    int answer = 0;
    for(int i=2;i<=n;i++){
        if(!checked[i])
            answer++;
    }
    return answer;
}