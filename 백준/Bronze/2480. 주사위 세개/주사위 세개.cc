#include<iostream>
using namespace std;
int main() {
	int flag = 0,index=0;
	int arr[3] = { 0, };
	for (int x = 0; x < 3; x++)
		cin >> arr[x];
	if (arr[0] == arr[1] && arr[1] == arr[2] && arr[0] == arr[2])
		cout << 10000 + arr[0] * 1000;
	else if (arr[0]==arr[1]&&arr[1]!=arr[2]) 
		cout << 1000 + arr[0] * 100;
	else if (arr[0] == arr[2] && arr[1] != arr[2])
		cout << 1000 + arr[0] * 100;
	else if (arr[0] != arr[1] && arr[1] == arr[2])
		cout << 1000 + arr[2] * 100;

	else {
		int max = 0;
		for (int x = 0; x < 3; x++) {
			if (max < arr[x])
				max = arr[x];
		}
		cout << max * 100;
	}
		
}