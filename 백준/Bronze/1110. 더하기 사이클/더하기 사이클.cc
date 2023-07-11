#include<iostream>
using namespace std;
int cycle(int num) {
	if (num == 0)
		return 1;
	else if (num == 1)
		return 60;
	int a, b, c;
	int d,count1=0;
	int k = num;
	for (;;) {
		a = k / 10;
		b = k % 10;
		c = a + b;
		count1++;
		if (c >= 10)
			c = c % 10;
		 d = b * 10 + c;
		 if (d == num)
			 break;
		 k = d;
		 
	}
	return count1;

}
int main() {
	int num;
	cin >> num;
	cout << cycle(num);

}