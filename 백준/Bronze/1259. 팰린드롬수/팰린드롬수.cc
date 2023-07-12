#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
using namespace std;
char str[6];
void abc() {
	int len1 = strlen(str);
	char str2[6];
	strcpy(str2, str);
	for (int x = 0; x < len1 / 2; x++)
		swap(str[x], str[len1 - 1 - x]);
	if (strcmp(str, str2) == 0)
		cout << "yes" << endl;
	else
		cout << "no" << endl;

}
int main() {
	while (1) {
		cin >> str;
		if (strcmp(str, "0") == 0)
			break;
		else
			abc();
	}
}