#include <iostream>
using namespace std;

int board[2200][2200];
int mns = 0, zero = 0, one = 0;
int flag;

void divide(int x, int y, int n) {
		flag = board[x][y]; 
		bool check = true; 

		for (int i = x; i < x + n; i++) {
			for (int j = y; j < y + n; j++) {
				if (board[i][j] != flag) {
					check = false;
					break;	
				}
			}
		}

		if (check) {
			if (flag == -1) mns++;
			else if (flag == 0) zero++;
			else if (flag == 1) one++;
		}
		else {
			n = n / 3;
			divide(x, y, n);
			divide(x, y + n * 2, n);
			divide(x, y + n, n);

			divide(x + n * 2, y, n);
			divide(x + n * 2, y + n * 2, n);
			divide(x + n * 2, y + n, n);

			divide(x + n, y, n);
			divide(x + n, y + n * 2, n);
			divide(x + n, y + n, n);
		}
		return;
	}

int main() {
		int n;
		cin >> n;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> board[i][j];
			}
		}

		divide(0, 0, n);
		cout << mns << " " << zero << " " << one << endl;
		return 0;
}
