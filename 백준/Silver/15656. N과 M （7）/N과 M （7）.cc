
#include<stdio.h>
#include<stdlib.h>
int arr[8];
int arr2[8];
int arr3[8];
int n, m;
void abc(int a);
int compare(const void* a, const void* b);
int compare(const void* a, const void* b) {
	int n1 = *(int*)a;
	int n2 = *(int*)b;
	if (n1 > n2)
		return 1;
	if (n1 < n2)
		return -1;
	else
		return 0;

}
int main() {
	scanf("%d %d", &n, &m);
	for (int x = 0; x < n; x++)
		scanf("%d", &arr[x]);
	qsort(arr,n, sizeof(int), compare);
	abc(0);

}
void abc(int a) {
	if (a == m) {
		for (int x = 0; x < m; x++)
			printf("%d ", arr2[x]);
		printf("\n");
		return;
	}
	for (int x = 0; x < n; x++) {
		arr2[a] = arr[x];
		abc(a + 1);
		arr2[a] = 0;
	}


}