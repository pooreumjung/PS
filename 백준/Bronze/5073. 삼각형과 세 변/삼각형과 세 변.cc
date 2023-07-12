#include <iostream>

int main()
{
	int a, b, c;

	while (1)
	{
		scanf("%d %d %d", &a, &b, &c);

		if (a == 0 && b == 0 && c == 0)
			break;
		int m = (a>b?a:b) > c ? (a>b ? a:b) : c; // 가장 긴 변 
		if (m<a+b+c-m)
		{
			if (a == b && a == c)
				printf("Equilateral\n");
			else if (a == b || b == c || a == c)
				printf("Isosceles\n");
			else
				printf("Scalene\n");
		}
		else
			printf("Invalid\n");
	}
}