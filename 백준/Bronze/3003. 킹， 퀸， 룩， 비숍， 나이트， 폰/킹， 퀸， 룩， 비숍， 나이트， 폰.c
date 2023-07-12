#include <stdio.h>

int main() {
	int a[6], i;
	int b[6] = {1,1,2,2,2,8};
	
	scanf("%d %d %d %d %d %d", &a[0], &a[1], &a[2], &a[3], &a[4], &a[5]);
	
	for( i = 0; i < 6; i++ ) {
		printf("%d ", (b[i]-a[i]));
	}
	
	return 0;
}
