#include<iostream>
using namespace std;
int rev(int num);
int main() {
	int a, b;
	cin >> a >> b;
    int dx = rev(a);
    int dy = rev(b);
    int dz = dx + dy;
    int dx1 = rev(dz);
        cout << dx1;
}
int rev(int num) {
	if (num/1000!=0) {
        return (num / 1000) + ((num % 1000) / 100) * 10 + ((num % 100) / 10) * 100 + (num % 10) * 1000;
    
    }
    else if (num / 100 != 0) {
        return (num / 100) + ((num % 100) / 10) * 10 + (num % 10) * 100;
    }
    else if (num / 10 != 0) {
        return (num / 10) + (num % 10) * 10;
    }
    else {
        return num;


	}
}