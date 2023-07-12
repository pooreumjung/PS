#include<iostream>
#include<cstring>
using namespace std;
char a[100001];
char b[100001];
void reverse() {
	for (int x = 0; x < strlen(b) / 2; x++)
		swap(b[x], b[strlen(b) - x - 1]);
	cout << b;
	fill_n(b, strlen(b), 0);
}
int main() {
	cin.getline(a, 100001);
	int k = 0;
	int c = 0;
	int count = 0;
	for (int x = 0; x < strlen(a); x+=k) {
		if (a[x] == '<') {
			for (int y = x;; y++) {
				if (a[y] == '>') {
					cout << ">";
					k = y+1-x;
					break;
				}
				else
					cout << a[y];
			}
		}
		else {
			for (int y = x;; y++) {
				if (a[y] == '<'||a[y]==NULL) {
					k = y-x;
					break;
				}
				else if (a[y] == ' ') {
					count = 1;
					k = y - x + 1;
					break;
				}
				else {
					b[c] = a[y];
					c++;
				}
					
			}
			reverse();
			if (count == 1) {
				cout << " ";
				count = 0;
			}
			c = 0;
		}
	}

}