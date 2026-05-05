#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int answer = 0, maxHealth = health, attackIndex = 0, curMinute = 0, continueTime=0;
    
    for(vector<int>v : attacks){
        // 몬스터가 공격할 시간까지 우선 충전(시전 시간, 현재 시간, 현재 체력)
        while(true){
            // 현재 시간이 몬스터한테 공격받을 시간이라면 종료
            curMinute++;
            if(curMinute >= v[0])
                break;
            // 지속시간 갱신 + 현재 체력 갱신
            continueTime++;            
            health += bandage[1];
            
            // 시전 시간을 다 채웠다면(추가 체력 + 시전 시간 0으로 초기화)
            if(continueTime == bandage[0]){
                health += bandage[2];
                if(health > maxHealth)
                    health = maxHealth;
                continueTime = 0;
            }
            
            // 최대체력을 넘어설 수 없음
            if(health > maxHealth)
                health = maxHealth;
            cout<<health<<" ";
        }
                
        // 몬스터 공격(체력 감소 + 연속 시간 0으로 처리)
        health -= v[1];
        continueTime = 0;
        if(health <= 0)
            return -1;   
        cout<<health<<'\n';
    }
    return health;
}