#include <iostream>
using namespace std;
int arr[101];
int main()
{
	
	int N, M;
	int a, b, c;
	cin >> N >> M;	
	for (int i = 0; i < M; i++){  
		cin >> a >> b >> c;  
		for (int j = a - 1; j < b; j++)  
		{
			arr[j] = c; 
		}
	}

	for (int i = 0; i < N; i++)  
	{
		cout << arr[i] << " ";  
	}

	return 0;
}