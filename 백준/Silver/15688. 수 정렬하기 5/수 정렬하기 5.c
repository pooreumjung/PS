#include<stdio.h>
#define mat 2000002
int N, arr[mat];
int main() {
	
	scanf("%d", &N);
	for (int x = 0; x < N; x++) {
		int k;
		scanf("%d", &k);
		arr[k + 1000000]++;
	}
	for (int x = 0; x < mat; x++) {
		if (arr[x] > 0) {
			while (arr[x]) {
				printf("%d\n", x - 1000000);
				arr[x]--;
			}

		}

	}

}

