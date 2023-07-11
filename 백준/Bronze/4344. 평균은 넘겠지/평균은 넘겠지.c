

#include<stdio.h>
int arr[1001] = { 0 };
int main() {
	int n,m;
	scanf("%d", &n);
	for (int x = 0; x < n; x++) {
		scanf("%d", &m);
		int sum=0,cnt=0;
		float res = 0;
		for (int y = 0; y < m; y++) {
			scanf("%d", &arr[y]);
			sum += arr[y];
		}
		res = (float)(sum / m);
		for (int k = 0; k < m; k++) {
			if (res < arr[k])
				cnt++;
		}
		float num = (float)(cnt) / (float)(m) * 100;
		printf("%.3f%%\n", num);
	}



}