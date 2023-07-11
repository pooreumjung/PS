#include<iostream>
#include<string>
using namespace std;
string str;
int dat[125];
void find(char al);
int find2();
int max1 = 0;
int main() {
	cin >> str;
	char a = 'a';
	char b = 'A';
	int dx = 0;
	for (int x = 0; x < 26; x++) {
		find(a);
		a += 1;
	}
	for (int x = 0; x < 26; x++) {
		find(b);
		b += 1;
	}
	for (int x = 97; x <= 124; x++) {
		dat[x] = dat[x] + dat[x - 32];
	}
	for (int x = 97; x <=124; x++) {
		if (max1 < dat[x]) {
			max1 = dat[x];
			dx = x;
		}
	}
	int len=find2();
	if (len == 1)
		cout << "?";
	if (len == 0)
		cout << (char)(dx-32);
}
void find(char al) {
	int b = 0, cnt = 0;
	while (1) {
		int res = str.find(al, b);
		if (res == -1)
			break;
		int num = (int)al;
		dat[num]++;
		b = res + 1;
	}


}
int find2() {
	int cnt = 0;
	for (int x = 97; x < 125; x++) {
		if (max1 == dat[x])
			cnt++;
	}
	if (cnt >= 2)
		return 1;
	else
		return 0;
}