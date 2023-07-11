#include<stdio.h>
int find(int a);
int dp[31];
int main() {
	int n;
	scanf("%d", &n);
	printf("%d", find(n));
}
int find(int a)
{    
    if(a==0)
        return 1;
    if(a==1)
        return 0;
    if(a==2)
        return 3;
	if (dp[a] != 0)
		return dp[a];
	dp[a] = 3 * find(a - 2);
	for (int x = 4; x <= a;x++) 
	{
		if (x % 2 == 0)
		{
			dp[a]+= 2 * find(a - x);
		}
	}
	return dp[a];

}

