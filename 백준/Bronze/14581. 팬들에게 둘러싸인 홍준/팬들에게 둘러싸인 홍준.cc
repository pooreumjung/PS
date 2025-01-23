#include <iostream>
#include <string>
using namespace std;

int main() {
    string id;
    cin >> id;

    // 팬들에게 둘러싸인 홍준 출력
    cout << ":fan::fan::fan:" << endl;
    cout << ":fan::" << id << "::fan:" << endl;
    cout << ":fan::fan::fan:" << endl;

    return 0;
}
