#include <stdio.h>
#include <string.h>
void Reverse(char* arr, int n);

int main(void)
{
	char word[50], w_1[50], w_2[50], w_3[50];
	char answer[50], rev[50];
	int pevot_1, pevot_2, i , j = 0;

	scanf("%s", word);

	for (pevot_1 = 0;pevot_1 < strlen(word) - 2;pevot_1++)
	{
		for (pevot_2 = pevot_1 + 1;pevot_2 < strlen(word) - 1;pevot_2++)
		{
			for (i = 0;i < pevot_1 + 1;i++)  
				w_1[i] = word[i];
			Reverse(w_1, pevot_1 + 1);
			for (i = 0;i < pevot_1 + 1;i++)
				rev[i] = w_1[i];

			for (i = pevot_1 + 1;i < pevot_2 + 1;i++)
				w_2[j++] = word[i];
			Reverse(w_2, pevot_2 - pevot_1);
			j = 0;
			for (i = pevot_1 + 1;i < pevot_2 + 1;i++)
				rev[i] = w_2[j++];
			j = 0;

			for (i = pevot_2 + 1;i < strlen(word);i++)
				w_3[j++] = word[i];
			Reverse(w_3, strlen(word) - pevot_2 - 1);
			j = 0;
			for (i = pevot_2 + 1;i < strlen(word);i++)
				rev[i] = w_3[j++];
			j = 0;
			if (pevot_1 == 0 & pevot_2 == 1)
			{
				for (i = 0;i < strlen(word);i++)
					answer[i] = rev[i];
			}

			if(strcmp(answer,rev)>0)
			{
				for (i = 0;i < strlen(word);i++)
					answer[i] = rev[i];
			}
		}
	}
	for (i = 0;i < strlen(word);i++)
		printf("%c", answer[i]);

	return 0;
}

void Reverse(char* arr, int n)
{
	int i;
	char tmp;

	for (i = 0;i < n / 2;i++)
	{
		tmp = arr[i];
		arr[i] = arr[n - 1 - i];
		arr[n - 1 - i] = tmp;
	}
}