#include <iostream>

using namespace std;

int main(void) {
    int arr[100][100] = {0,};
    int result = 0, numOftry;

    cin >> numOftry;
    for (int i = 0; i < numOftry; i++) {
        int row, col;
        cin >> row >> col;
        row = 99 - row;
        for (int j = row; j > row - 10; j--) {
            for (int k = col; k < col + 10; k++) {
                arr[j][k] = 1;
            }
        }
    }
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            if (arr[i][j] == 1) result++;
        }
    }
    cout << result << endl;

    return 0;
}