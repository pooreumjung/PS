#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;

	int M = 0;
	double sum = 0;
	for (int i = 0; i < N; i++)
	{
		int n;
		cin >> n;

		if (n > M)
			M = n;

		sum += n;
	}

	double result = (sum / N) / M * 100;

	cout << result;

	return 0;
}
