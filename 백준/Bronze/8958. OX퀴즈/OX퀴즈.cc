#include<iostream>
#include<cstring>
using namespace std;
int ret(char *a) {
	int result = 0, index, max1,dif;
	int x = 0;
	 while(x <strlen(a)) {
		 if (a[x] == 'O') {
			 index = x;
			 dif = x;
			 while (index < strlen(a)) {
				 index++;
				 if (index == strlen(a)) {
					 max1 = index;
					 break;
				 }
				 else if (a[index] == 'X') {
					 max1 = index;
					 break;
				 }
			 }
			 for (int k = 1; k<=max1 - dif; k++)
				 result += k;
			 x = index;
		 }
		 else
			 x++;
	}

	return result;

}
int main() {
	int num;
	cin >> num;
	for (int x = 0; x < num; x++) {
		char input[81];
		cin >> input;
		int a = ret(input);
		cout << a << endl;
	}
}
