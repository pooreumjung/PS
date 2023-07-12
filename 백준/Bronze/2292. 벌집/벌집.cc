#include <stdio.h>
int main()
{
	int i = 1; 
 	int sumA = 1, sumB = 1; 
	int n;
	scanf("%d", &n);
	if (n == 1)
	{
		printf("1");
		return 0;
	}

	while (1)
	{
		sumB = sumB + 6 * i;
		sumA = sumA + 6 * (i - 1); 
		i++; 
		if (n > sumA && n <= sumB)
		{
			printf("%d", i);
			break;
		}

	}

}