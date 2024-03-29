#include<stdio.h>
int n, m;
int arr[8];
int arr2[8];
int arr3[8];
void abc(int a);
int main() {
	scanf("%d %d",&n,&m);
	for (int x = 0; x < n; x++)
		arr[x] = x + 1;
	abc(0);
}
void abc(int a) {
	if (a == m) {
		for (int x = 0; x < m; x++)
			printf("%d ",arr2[x]);
		printf("\n");
		return;
	}
	for (int x = 0; x < n; x++) {
		if (arr3[x] == 0) {
			arr3[x] = 1;
			arr2[a] = arr[x];
			abc(a + 1);
			arr2[a] = 0;
			arr3[x] = 0;
		}
	}




}