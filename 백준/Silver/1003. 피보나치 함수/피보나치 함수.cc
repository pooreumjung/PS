#include <iostream>
using namespace std;
int arr[41];
int fibonacci(int n)
{
	if (n == 0)
		arr[0] = 0;
	else if (n == 1)
		arr[1] = 1;
	else if (arr[n] == 0)
		arr[n] = fibonacci(n - 1) + fibonacci(n - 2);
	return arr[n];
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int num;
	cin >> num;
	fibonacci(40);

	int N;
	for (int x = 0; x < num; x++)
	{
		cin >> N;
		if (N == 0)
			cout << "1 0" << '\n';
		else
			cout << arr[N - 1] << " " << arr[N] << '\n';
	}
	return 0;
}
