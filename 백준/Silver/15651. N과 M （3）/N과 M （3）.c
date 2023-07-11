#include<stdio.h>
void abc(int a);
int arr[7] = { 1,2,3,4,5,6,7 };
int arr1[7];
int arr2[7];
int n, m;
int main() {
	scanf("%d %d",&n,&m);
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
		arr2[a] = arr[x];
		abc(a + 1);
		
	}
}