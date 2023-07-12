#include <stdio.h>
int table[100001];
int main(void)
{
	int n;
	int m;
	int sum = 0;
	int temp;
	scanf("%d%d", &n, &m);

	table[0] = 0;
	scanf("%d", &table[1]);

	for (int i = 2; i <= n; i++)
	{
		scanf("%d", &temp);
		table[i] = temp + table[i - 1];
	}

	int s;
	int e;

	for (int i = 0; i < m; i++)
	{
		scanf("%d%d", &s, &e);
		printf("%d\n", table[e] - table[s - 1]);
	}
}
