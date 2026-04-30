#include <string>
#include <vector>
#include <cmath>

using namespace std;

int func(int num){
    int count = 0;

    for(int i = 1; i <= sqrt(num); i++){
        if(num % i == 0){
            count++;
            if(num / i != i)
                count++;
        }
    }

    return count;
}

int solution(int number, int limit, int power) {
    int answer = 0;

    for(int i = 1; i <= number; i++){
        int count = func(i);

        if(count <= limit)
            answer += count;
        else
            answer += power;
    }

    return answer;
}