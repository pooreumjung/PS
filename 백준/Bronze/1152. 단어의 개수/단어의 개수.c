#include<stdio.h>
#include<ctype.h>
#include<string.h>
char arr[1000001];
int find1();
int main(){
	gets(arr);
	int pass = find1();
	if (arr[0] == ' ')
		printf("%d",pass);
	else
		printf("%d",pass+1);
}
int find1() {
	int len = strlen(arr);
	int from = 0;
	for (int x = 0; x < len-1; x++) {
		if (arr[x] == ' ')
			from++;
	}
	return from;

}