#include<iostream>
#include<cstring>
using namespace std;
int main() {
	char a[7];
	
	cin >> a;
	
	int sum = 0,flag=1;
	for (int x = 0; x < strlen(a) / 2; x++) {
		swap(a[x],a[strlen(a) - x - 1]);
	}
	for (int x = 0; x < strlen(a); x++) {
		if (a[x] == 'A') {
			sum += flag * 10;
			flag*=16;
		}
		else if (a[x] == 'B') {
			sum += flag * 11;
			flag*=16;
		}
		else if (a[x] == 'C') {
			sum += flag * 12;
			flag*=16;
		}
		else if (a[x] == 'D') {
			sum += flag * 13;
			flag*=16;
		}
		else if (a[x] == 'E') {
			sum += flag * 14;
			flag*=16;
		}
		else if (a[x] == 'F') {
			sum += flag * 15;
			flag*=16;
		}
		else {
			sum += flag * (a[x] - 48);
			flag*=16;
		}
	}
		cout << sum;
}

