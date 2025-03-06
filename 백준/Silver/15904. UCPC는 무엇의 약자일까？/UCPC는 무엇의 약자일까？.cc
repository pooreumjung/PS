#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    getline(cin, s); 

    string target = "UCPC";
    int idx = 0; 

    for (char c : s) {
        if (c == target[idx]) { 
            idx++; 
            if (idx == 4) break; 
        }
    }

    if (idx == 4)
        cout << "I love UCPC" << endl;
    else
        cout << "I hate UCPC" << endl;

    return 0;
}