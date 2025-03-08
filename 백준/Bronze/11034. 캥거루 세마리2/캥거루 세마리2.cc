#include <iostream>
using namespace std;

int main() {
    int A, B, C;
    
    while (cin >> A >> B >> C) { // 입력이 계속 주어지는 경우 처리
        int move1 = B - A - 1;
        int move2 = C - B - 1;
        cout << max(move1, move2) << endl;
    }

    return 0;
}
